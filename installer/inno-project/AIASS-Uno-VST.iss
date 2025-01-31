[Setup]
AppName=AIASS-Uno-VST
AppVersion=0.9.7
DefaultDirName={pf}\AIASS-Uno-VST
DefaultGroupName=AIASS-Uno-VST
LicenseFile=license.txt
OutputDir=.\Output
OutputBaseFilename=AIASS-Uno-VST-v0.9.7-Windows-x64-Installer
Compression=lzma
SolidCompression=yes
ArchitecturesInstallIn64BitMode=x64
SetupIconFile=icon.ico

[Files]
Source: "AIASS-UNO.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "hardsid.dll"; DestDir: "{win}"; Flags: ignoreversion
Source: "readme.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "AIASS-Uno-Manual.pdf"; DestDir: "{app}"; Flags: ignoreversion
Source: "VC_redist.x64.exe"; DestDir: "{tmp}"; Flags: deleteafterinstall
Source: "AIASS-UNO.dll"; DestDir: "{code:GetVST2Dir}"; Flags: ignoreversion
Source: "AIASS-UNO.vst3\*"; DestDir: "{code:GetVST3Dir}"; Flags: ignoreversion recursesubdirs

[Icons]
Name: "{group}\AIASS-UNO"; Filename: "{app}\AIASS-UNO.exe"
Name: "{group}\Readme"; Filename: "{app}\readme.txt"
Name: "{group}\AIASS-Uno Manual"; Filename: "{app}\AIASS-Uno-Manual.pdf"
Name: "{userdesktop}\AIASS-UNO"; Filename: "{app}\AIASS-UNO.exe"; Tasks: desktopicon

[Tasks]
Name: "desktopicon"; Description: "Create a desktop shortcut"; GroupDescription: "Additional icons:"; Flags: unchecked

[Run]
Filename: "{tmp}\vc_redist.x64.exe"; Parameters: "/quiet /norestart"; Check: NeedsVCpp
Filename: "{app}\readme.txt"; Description: "View Readme"; Flags: postinstall shellexec skipifsilent
Filename: "{app}\AIASS-Uno-Manual.pdf"; Description: "View Manual"; Flags: postinstall shellexec skipifsilent
Filename: "{app}\AIASS-UNO.exe"; Description: "Launch the application"; Flags: nowait postinstall skipifsilent

[Code]
var
  VST2DirPage, VST3DirPage: TInputDirWizardPage;

function NeedsVCpp: Boolean;
begin
  Result := not RegKeyExists(HKLM, 'SOFTWARE\Microsoft\VisualStudio\14.0\VC\Runtimes\x64');
end;

function GetVST2Dir(Param: string): string;
begin
  Result := VST2DirPage.Values[0];
end;

function GetVST3Dir(Param: string): string;
begin
  Result := VST3DirPage.Values[0];
end;

procedure InitializeWizard;
begin
  VST2DirPage := CreateInputDirPage(
    wpSelectDir, 
    'VST2 Plugin Directory', 
    'Please select the directory for the VST2 plugin:', 
    'Choose the destination folder for the VST2 plugin. The default is "C:\Program Files\VstPlugins\".', 
    False, 
    ''
  );
  VST2DirPage.Add('');
  VST2DirPage.Values[0] := 'C:\Program Files\VstPlugins';

  VST3DirPage := CreateInputDirPage(
    wpSelectDir, 
    'VST3 Plugin Directory', 
    'Please select the directory for the VST3 plugin:', 
    'Choose the destination folder for the VST3 plugin. The default is "C:\Program Files\Common Files\VST3\".', 
    False, 
    ''
  );
  VST3DirPage.Add('');
  VST3DirPage.Values[0] := 'C:\Program Files\Common Files\VST3';
end;

[UninstallDelete]
Type: filesandordirs; Name: "{userappdata}\SIDBlaster ASID Player"
Type: filesandordirs; Name: "{code:GetVST3Dir}\AIASS-UNO.vst3"
