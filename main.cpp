//---------------------------------------------------------------------------
// XMLLevelWriter was developed by Yazev Yuriy
// I used C++ with C++Builder to develop an application
// and TinyXML to work with XML files,
// I created this program to develop levels for myRiseOfAtlantis game
// simply, I use Visual C++ to make games, however,
// I use C++Builder to make win-applicatons :)

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "tinyxml\tinyxml.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLevWrt *LevWrt;//window-object
TPanel *pushedPanel;//panel-component which was pushed by user
const String compFilePath = "FilePath",//name of a FilePath component
             compObjType  = "ObjType", //name of an ObjType component
             compPanel    = "Panel",   //name of a Panel component
             compPanelLab = "sun p";//label of a panel component
String filename = "";//path to file is saved here
bool modified = false;//a flag to watch a level's changes
int sunnum = 1;//sun pieces' number
const int cm = 7;//component number
//---------------------------------------------------------------------------
__fastcall TLevWrt::TLevWrt(TComponent* Owner)
        : TForm(Owner)
{
}

void TLevWrt::Change_State(TPanel *obj, String s, TColor col)
{
 if (obj->Caption.Pos(compPanelLab) != NULL)
 {
  String s = obj->Caption;
  String dest;
  for (int i = s.Length(); i > 0; i--)
  {
   if (s[i] != 'p') dest.Insert(s[i], 0);
   else break;
  }
   TComponent* comp = Application->FindComponent(compObjType + IntToStr(StrToInt(dest) + cm));
   comp->Free();
   comp = Application->FindComponent(compFilePath + IntToStr(StrToInt(dest) + cm));
   comp->Free();
   comp = Application->FindComponent("OpnDlg" + IntToStr(StrToInt(dest) + cm));
   comp->Free();
 }
 String line = s.Delete(s.Pos("&"), 1);
 obj->Caption = line;
 obj->Hint = line;
 obj->Color = col;
 obj->Font->Color = clBlack;
 modified = true;
}

void TLevWrt::Clear_ObjType()
{
ObjType0->Text = "";
ObjType1->Text = "";
ObjType2->Text = "";
ObjType3->Text = "";
ObjType4->Text = "";
ObjType5->Text = "";
ObjType6->Text = "";
ObjType7->Text = "";
FilePath0->Text = "";
FilePath1->Text = "";
FilePath2->Text = "";
FilePath3->Text = "";
FilePath4->Text = "";
FilePath5->Text = "";
FilePath6->Text = "";
FilePath7->Text = "";
for (int i = 8; i <= 17; i++)
{
 TComponent* comp = Application->FindComponent(compObjType + IntToStr(StrToInt(i)));
   comp->Free();
   comp = Application->FindComponent(compFilePath + IntToStr(StrToInt(i)));
   comp->Free();
   comp = Application->FindComponent("OpnDlg" + IntToStr(StrToInt(i)));
   comp->Free();
}
}
//---------------------------------------------------------------------------
void __fastcall TLevWrt::Panel1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
if (Button == mbRight)
{
pushedPanel = dynamic_cast<TPanel*>(Sender);
if ((pushedPanel->Caption == "") || (pushedPanel->Caption == "cell")
|| (pushedPanel->Caption.Pos(compPanelLab) != NULL))
ppbLock->Enabled = false; else ppbLock->Enabled = true;

if (pushedPanel->Caption.Pos(compPanelLab) != NULL)
ppbSunPart->Enabled = false;
else
ppbSunPart->Enabled = true;
}
}
//---------------------------------------------------------------------------
void __fastcall TLevWrt::ppbCellClick(TObject *Sender)
{
if (pushedPanel != NULL) Change_State(pushedPanel,
dynamic_cast<TMenuItem*>(Sender)->Caption, clWhite);
}
//---------------------------------------------------------------------------
void __fastcall TLevWrt::ppbSpaceClick(TObject *Sender)
{
if (pushedPanel != NULL) Change_State(pushedPanel, "", clBtnFace);
}
//---------------------------------------------------------------------------
void __fastcall TLevWrt::Exit1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TLevWrt::OpnDlg1Click(TObject *Sender)
{
OpenImageDialog->Execute();
String fn = OpenImageDialog->FileName;
if (fn != "")
{
String s = dynamic_cast<TButton*>(Sender)->Name;
String p;
for (int i = s.Length(); i > 0; i--)
{
if (s[i] != 'g') p.Insert(s[i], 0);
else break;
}
String comp_name = compFilePath + p;
TComponent* comp = NULL;
if (StrToInt(p) <= 7)
comp = FindComponent(comp_name); else
comp = Application->FindComponent(comp_name);
if (comp != NULL)
dynamic_cast<TEdit*>(comp)->Text = fn;
}
}
//---------------------------------------------------------------------------
void __fastcall TLevWrt::mmbOpenLevelClick(TObject *Sender)
{
mmbNewClick(this);
OpenLevelDialog->Execute();
if (OpenLevelDialog->FileName != "")
{
filename = OpenLevelDialog->FileName;
char *fn = filename.c_str();
Load_Level(fn);
modified = false;
}
}
//---------------------------------------------------------------------------
void TLevWrt::Load_Level(const char *fn)
{
// этот кусок кода пожаловал сюда прямиком из myRiseOfAtlantis :)
// -> с некоторыми изменениями, конечно :)
	const char *pfile = "file", *pobject = "object", *plock = "lock",
                   *pbackground = "background", *psunp = "sun p";
	const char *elementName, *type, *path, *xp, *yp;
	float xpos, ypos;

	TiXmlDocument doc(fn);
	doc.LoadFile();
	TiXmlElement* root = doc.FirstChildElement("level");
	TiXmlElement* element = root->FirstChildElement();

	while (element != NULL)
{
	elementName = element->Value();
	if (stricmp(elementName, pfile) == 0)//file
	{
		TiXmlAttribute* fattr = element->FirstAttribute();//first attribute
		if (fattr)
		{
			type = fattr->Value();
			TiXmlAttribute* sattr = fattr->Next();//second attribute
			path = sattr->Value();
			xp = NULL;
			yp = NULL;
                if (stricmp(type, pbackground) == 0)
                {
                  ObjType0->Text = type;
                  FilePath0->Text = path;
                } else
                if (stricmp(type, plock) == 0)
                {
                  ObjType7->Text = type;
                  FilePath7->Text = path;
                } else
                if (strstr(type, psunp) != NULL)
                {
                   String s = path;
                   char *c = s.c_str();
                   Make_Objects(c);
                } else
                for (int i = 0; i <= 7; i++)
                {
                String comp_name = compObjType + IntToStr(i);
                TComponent* comp = FindComponent(comp_name);
                TComboBox* box = dynamic_cast<TComboBox*>(comp);
                if (box->Text == "")
                {
                 box->Text = type;
                 String comp_name2 = compFilePath + IntToStr(i);
                 TComponent* comp2 = FindComponent(comp_name2);
                 TEdit* edit = dynamic_cast<TEdit*>(comp2);
                 edit->Text = path;
                break;
                }
                }
		element = element->NextSiblingElement();
		}
	} else
	if (stricmp(elementName, pobject) == 0)//object
	{
		TiXmlAttribute* fattr = element->FirstAttribute();//first attribute
		if (fattr)
		{
			type = fattr->Value();
			TiXmlAttribute* sattr = fattr->Next();//second attribute
			xp = sattr->Value();
			TiXmlAttribute* tattr = sattr->Next();//third attribute
			yp = tattr->Value();
			if (xp != NULL)
			{
			xpos = atof(xp);
			}
			if (yp != NULL)
			{
			ypos = atof(yp);
			}
                        for (int i = 1; i <= 121; i++)
                        {
                         String comp_name = compPanel + IntToStr(i);
                         TComponent* comp = FindComponent(comp_name);
                         TPanel* panel = dynamic_cast<TPanel*>(comp);
                         if ((panel->Left == xpos) && (panel->Top == ypos))
                         {
                          if (stricmp(type, plock) == 0)
                          {
                           panel->Color = clBlack;
                           panel->Font->Color = clWhite;
                          } else
                          if (stricmp(type, pbackground) == 0)
                          {
                           break;
                          } else {
                          panel->Caption = type;
                          panel->Color = clWhite;
                          }
                         }
			}
		element = element->NextSiblingElement();
		}
	}
}
}

void TLevWrt::Clear_All_Cells()
{
for (int i = 1; i <= 121; i++)
 {
  String comp_name = compPanel + IntToStr(i);
  TComponent* comp = FindComponent(comp_name);
  TPanel* panel = dynamic_cast<TPanel*>(comp);
  panel->Caption = "";
  panel->Color = clBtnFace;
  panel->Font->Color = clBlack;
 }
}

void __fastcall TLevWrt::ppbLockClick(TObject *Sender)
{
if ((pushedPanel != NULL) || (pushedPanel->Caption != "")
|| (pushedPanel->Caption == "cell")
|| (pushedPanel->Caption.Pos(compPanelLab) != NULL))
{
if (pushedPanel->Color == clWhite)
{
Change_State(pushedPanel, pushedPanel->Caption, clBlack);
pushedPanel->Font->Color = clWhite;
modified = true;
} else
if (pushedPanel->Color == clBlack)
Change_State(pushedPanel, pushedPanel->Caption, clWhite);
}
}

//---------------------------------------------------------------------------
void TLevWrt::Save_Level(String fn)
{
      	TiXmlDocument doc;
	TiXmlElement* msg;
 	TiXmlDeclaration* decl = new TiXmlDeclaration("1.0", "UTF-8", "yes");
	doc.LinkEndChild(decl);

        TiXmlComment *comment1 = new TiXmlComment();
	comment1->SetValue("XML file was written using XMLLevelWriter");
	doc.LinkEndChild(comment1);
        TiXmlComment *comment2 = new TiXmlComment();
	comment2->SetValue("objects' size is 40 x 40");
	doc.LinkEndChild(comment2);

	TiXmlElement *root = new TiXmlElement("level");
	doc.LinkEndChild(root);

        const maxcomps = sunnum + cm;
        for (int i = 0; i <= maxcomps; i++)
        {
                String comp_name = compObjType + IntToStr(i);
                //
                TComponent* comp;
                if (i < 8) comp = FindComponent(comp_name); else
                comp = Application->FindComponent(comp_name);
                //
                if (comp != NULL)
                {
                TComboBox* box = dynamic_cast<TComboBox*>(comp);
                if (box->Text != "")
                {
                String comp_name2 = compFilePath + IntToStr(i);
                //
                TComponent* comp2;
                if (i < 8) comp2 = FindComponent(comp_name2); else
                comp2 = Application->FindComponent(comp_name2);
                //
                TEdit* edit = dynamic_cast<TEdit*>(comp2);
               	TiXmlElement *xfile;
	        xfile = new TiXmlElement("file");
                root->LinkEndChild(xfile);
       	        xfile->SetAttribute("type", box->Text.c_str());
        	xfile->SetAttribute("path", edit->Text.c_str());

                for (int j = 1; j <= 121; j++)  // обработка
                {
                if (i == 0)// объект - фон
                {
                 TiXmlElement *object = new TiXmlElement("object");
                	root->LinkEndChild(object);
                	object->SetAttribute("type", box->Text.c_str());
                	object->SetAttribute("dummy1", "");
                        object->SetAttribute("dummy2", "");
                 break;
                }
                   String panel_name = "Panel" + IntToStr(j);
                   TComponent* panel_comp = FindComponent(panel_name);
                   TPanel* panel = dynamic_cast<TPanel*>(panel_comp);
                   if (panel != NULL)
                   {
                   if (((box->Text == "cell") && (panel->Color != clBtnFace))
                   || (box->Text == panel->Caption)
                   || ((panel->Color == clBlack) && (box->Text == "lock")))
                   {
        TiXmlElement *object = new TiXmlElement("object");
        root->LinkEndChild(object);
        object->SetAttribute("type", box->Text.c_str());
        object->SetAttribute("x", panel->Left);
        object->SetAttribute("y", panel->Top);
                    }
                    }
                 }
                }
             }
         }
modified = false;
doc.SaveFile(fn.c_str());
}

void __fastcall TLevWrt::mmbSaveAsClick(TObject *Sender)
{
 filename = "";
 mmbSaveClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TLevWrt::mmbSaveClick(TObject *Sender)
{
if (ObjType0->Text == "background")
{
if (ObjType1->Text == "cell")
{
  if (filename != "")
  Save_Level(filename); else
  {
  if (SaveLevelDialog->Execute())
  {
  filename = SaveLevelDialog->FileName;
  if (filename != "")
  {
  if (filename.Pos(".xml") == 0) filename += ".xml";
  Save_Level(filename);
  }
  }
  }
} else Application->MessageBox("Second object type must be 'cell'", "Warning!!!", MB_OK);
} else Application->MessageBox("First object type must be 'background'", "Warning!!!", MB_OK);
}
//---------------------------------------------------------------------------

void __fastcall TLevWrt::mmbNewClick(TObject *Sender)
{
if ((modified) && (MessageDlg("Save changes before create a new level?",
mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes))
mmbSaveClick(this);
Clear_ObjType();
Clear_All_Cells();
modified = false;
sunnum = 1;
filename = "";
}
//---------------------------------------------------------------------------


void __fastcall TLevWrt::FormClose(TObject *Sender, TCloseAction &Action)
{
if (modified)
{
if (MessageDlg("Do you wanna save changes in the level " + filename + "?",
mtWarning, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) mmbSaveClick(this);
}
}
//---------------------------------------------------------------------------

void __fastcall TLevWrt::ppbSunPartClick(TObject *Sender)
{
if (pushedPanel != NULL)
{
Change_State(pushedPanel, compPanelLab + IntToStr(sunnum), clWhite);
Make_Objects(NULL);
}
}

void TLevWrt::Make_Objects(char *path)
{
// making objects
const top = 184, height = 24;
TComboBox* box = new TComboBox(Owner);
box->Name = compObjType + IntToStr(sunnum + cm);
box->Parent = LevWrt;
box->Text = compPanelLab + IntToStr(sunnum);
box->Left = 452;
box->Top = top + height * sunnum;
box->Width = 81;
box->Enabled = true;
box->Visible = true;
box = NULL;
// -----------------
TEdit* edit = new TEdit(Owner);
edit = new TEdit(Owner);
edit->Name = compFilePath + IntToStr(sunnum + cm);
edit->Parent = LevWrt;
if (path != NULL) edit->Text = path; else edit->Text = "";
edit->Left = 536;
edit->Top = top + height * sunnum;
edit->Width = 201;
edit->Enabled = true;
edit->Visible = true;
edit = NULL;
// -----------------
TButton* but = new TButton(Owner);
but->Name = "OpnDlg" + IntToStr(sunnum + cm);
but->Parent = LevWrt;
but->Caption = "Open File";
but->Left = 740;
but->Top = top + height * sunnum;
but->Width = 73;
but->Height = 21;
but->Enabled = true;
but->Visible = true;
but->OnClick = OpnDlg1->OnClick;
but = NULL;
// -----------------
sunnum++;
}
//---------------------------------------------------------------------------
