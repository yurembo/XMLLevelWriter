//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("XMLLevelWriter.res");
USEFORM("main.cpp", LevWrt);
USEUNIT("tinyxml\tinystr.cpp");
USE("tinyxml\tinystr.h", File);
USEUNIT("tinyxml\tinyxml.cpp");
USE("tinyxml\tinyxml.h", File);
USEUNIT("tinyxml\tinyxmlerror.cpp");
USEUNIT("tinyxml\tinyxmlparser.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TLevWrt), &LevWrt);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
