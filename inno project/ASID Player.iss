[Setup]
AppName=SB-ASID-Player
AppVersion=1.0
DefaultDirName={pf}\SB-ASID-Player
DefaultGroupName=SB-ASID-Player
LicenseFile=license.txt
OutputDir=.\Output
OutputBaseFilename=SIDBlaster-ASID-Player-v1.0-Windows-x64-Installer
Compression=lzma
SolidCompression=yes
ArchitecturesInstallIn64BitMode=x64
SetupIconFile=icon.ico

[Files]
Source: "SIDBlaster-ASID-Player.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "hardsid.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "readme.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "VC_redist.x64.exe"; DestDir: "{tmp}"; Flags: deleteafterinstall

[Icons]
Name: "{group}\SB-ASID-Player"; Filename: "{app}\SIDBlaster-ASID-Player.exe"
Name: "{group}\readme"; Filename: "{app}\readme.txt"
Name: "{userdesktop}\SB-ASID-Player"; Filename: "{app}\SIDBlaster-ASID-Player.exe"; Tasks: desktopicon

[Tasks]
Name: "desktopicon"; Description: "Desktop-Verknüpfung erstellen"; GroupDescription: "Zusätzliche Icons:"; Flags: unchecked

[Run]
Filename: "{tmp}\vc_redist.x64.exe"; Parameters: "/quiet /norestart"; Check: NeedsVCpp
Filename: "{app}\readme.txt"; Description: "Readme anzeigen"; Flags: postinstall shellexec skipifsilent
Filename: "{app}\SIDBlaster-ASID-Player.exe"; Description: "Programm starten"; Flags: nowait postinstall skipifsilent

[Code]
function NeedsVCpp: Boolean;
begin
  Result := not RegKeyExists(HKLM, 'SOFTWARE\Microsoft\VisualStudio\14.0\VC\Runtimes\x64');
end;

[UninstallDelete]
Type: filesandordirs; Name: "{userappdata}\SIDBlaster ASID Player"