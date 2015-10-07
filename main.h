//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TLevWrt : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel;
        TPanel *Panel1;
        TPopupMenu *PopupMenu1;
        TMenuItem *ppbSpace;
        TMenuItem *ppbCell;
        TMenuItem *ppbRuby;
        TMenuItem *ppbHelmet;
        TMenuItem *ppbGold;
        TMenuItem *ppbGreenSun;
        TMenuItem *ppbSeashell;
        TPanel *Panel2;
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TPanel *Panel3;
        TMenuItem *Exit1;
        TPanel *Panel4;
        TPanel *Panel5;
        TPanel *Panel6;
        TPanel *Panel7;
        TPanel *Panel8;
        TPanel *Panel9;
        TPanel *Panel10;
        TPanel *Panel11;
        TPanel *Panel12;
        TPanel *Panel13;
        TPanel *Panel14;
        TPanel *Panel15;
        TPanel *Panel16;
        TPanel *Panel17;
        TPanel *Panel18;
        TPanel *Panel19;
        TPanel *Panel20;
        TPanel *Panel21;
        TPanel *Panel22;
        TPanel *Panel23;
        TPanel *Panel24;
        TPanel *Panel25;
        TPanel *Panel26;
        TPanel *Panel27;
        TPanel *Panel28;
        TPanel *Panel29;
        TPanel *Panel30;
        TPanel *Panel31;
        TPanel *Panel32;
        TPanel *Panel33;
        TPanel *Panel34;
        TPanel *Panel35;
        TPanel *Panel36;
        TPanel *Panel37;
        TPanel *Panel38;
        TPanel *Panel39;
        TPanel *Panel40;
        TPanel *Panel41;
        TPanel *Panel42;
        TPanel *Panel43;
        TPanel *Panel44;
        TPanel *Panel45;
        TPanel *Panel46;
        TPanel *Panel47;
        TPanel *Panel48;
        TPanel *Panel49;
        TPanel *Panel50;
        TPanel *Panel51;
        TPanel *Panel52;
        TPanel *Panel53;
        TPanel *Panel54;
        TPanel *Panel55;
        TPanel *Panel56;
        TPanel *Panel57;
        TPanel *Panel58;
        TPanel *Panel59;
        TPanel *Panel60;
        TPanel *Panel61;
        TPanel *Panel62;
        TPanel *Panel63;
        TPanel *Panel64;
        TPanel *Panel65;
        TPanel *Panel66;
        TPanel *Panel67;
        TPanel *Panel68;
        TPanel *Panel69;
        TPanel *Panel70;
        TPanel *Panel71;
        TPanel *Panel72;
        TPanel *Panel73;
        TPanel *Panel74;
        TPanel *Panel75;
        TPanel *Panel76;
        TPanel *Panel77;
        TPanel *Panel78;
        TPanel *Panel79;
        TPanel *Panel80;
        TPanel *Panel81;
        TPanel *Panel82;
        TPanel *Panel83;
        TPanel *Panel84;
        TPanel *Panel85;
        TPanel *Panel86;
        TPanel *Panel87;
        TPanel *Panel88;
        TPanel *Panel89;
        TPanel *Panel90;
        TPanel *Panel91;
        TPanel *Panel92;
        TPanel *Panel93;
        TPanel *Panel94;
        TPanel *Panel95;
        TPanel *Panel96;
        TPanel *Panel97;
        TPanel *Panel98;
        TPanel *Panel99;
        TPanel *Panel100;
        TPanel *Panel101;
        TPanel *Panel102;
        TPanel *Panel103;
        TPanel *Panel104;
        TPanel *Panel105;
        TPanel *Panel106;
        TPanel *Panel107;
        TPanel *Panel108;
        TPanel *Panel109;
        TPanel *Panel110;
        TPanel *Panel111;
        TPanel *Panel112;
        TPanel *Panel113;
        TPanel *Panel114;
        TPanel *Panel115;
        TPanel *Panel116;
        TPanel *Panel117;
        TPanel *Panel118;
        TPanel *Panel119;
        TPanel *Panel120;
        TPanel *Panel121;
        TComboBox *ObjType1;
        TEdit *FilePath1;
        TComboBox *ObjType2;
        TEdit *FilePath2;
        TButton *OpnDlg1;
        TComboBox *ObjType3;
        TEdit *FilePath3;
        TButton *OpnDlg2;
        TComboBox *ObjType4;
        TEdit *FilePath4;
        TButton *OpnDlg3;
        TComboBox *ObjType5;
        TEdit *FilePath5;
        TButton *OpnDlg4;
        TOpenDialog *OpenImageDialog;
        TButton *OpnDlg5;
        TMenuItem *ppbSunPart;
        TComboBox *ObjType6;
        TEdit *FilePath6;
        TButton *OpnDlg6;
        TOpenDialog *OpenLevelDialog;
        TMenuItem *mmbOpenLevel;
        TMenuItem *ppbLock;
        TMenuItem *mmbSave;
        TMenuItem *mmbSaveAs;
        TSaveDialog *SaveLevelDialog;
        TMenuItem *mmbNew;
        TComboBox *ObjType0;
        TEdit *FilePath0;
        TButton *OpnDlg0;
        TComboBox *ObjType7;
        TEdit *FilePath7;
        TButton *OpnDlg7;
        TLabel *Label1;
        TLabel *Label2;
        void __fastcall Panel1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ppbCellClick(TObject *Sender);
        void __fastcall ppbSpaceClick(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall OpnDlg1Click(TObject *Sender);
        void __fastcall mmbOpenLevelClick(TObject *Sender);
        void __fastcall ppbLockClick(TObject *Sender);
        void __fastcall mmbSaveAsClick(TObject *Sender);
        void __fastcall mmbSaveClick(TObject *Sender);
        void __fastcall mmbNewClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ppbSunPartClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TLevWrt(TComponent* Owner);
        void Change_State(TPanel *obj, String s, TColor col);//changes a state of an object
        void Load_Level(const char *fn);//loads a level from a xml file
        void Clear_ObjType();//cleans all objtypes components
        void Clear_All_Cells();//changes a condition of all cells to default status
        void Save_Level(String fn);//saves a level to a xml file
        void Make_Objects(char *path);//creates objects
};
//---------------------------------------------------------------------------
extern PACKAGE TLevWrt *LevWrt;
//---------------------------------------------------------------------------
#endif
