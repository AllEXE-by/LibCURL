program project1;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes, SysUtils, CustApp, LibCURL
  { you can add units after this };

type

  { TCURLTest }

  TCURLTest = class(TCustomApplication)
  protected
    procedure DoRun; override;
  public
    constructor Create(TheOwner: TComponent); override;
    destructor Destroy; override;
  end;

{ TCURLTest }

procedure TCURLTest.DoRun;
var
  Handle : TCURLHandle = nil;
  ECode  : TCURLCode = CURL_LAST;
  URL    : String = '';
  urlPOST: String = '';
begin
  Handle := curl_easy_init();
  URL:= 'https://narodmon.ru/post';
  urlPOST:= '{"devices":[{"mac": "123123123123", "name": "devices", "owner": "alexeidg", "lat": 53.138419, "lon": 24.815008, "alt": 133,';
  urlPOST:= urlPOST + '"sensors": [{ "id": "T1", "name": "SENSOR NAME", "value": 23.50, "unit": "C" }]}]}';
  writeln(urlPOST);
  if Handle <> nil then
  begin
   ECode:= curl_easy_setopt(Handle, CURLOPT_SSL_VERIFYPEER, 0); // подлинность сертификата однорангового узла/
   ECode:= curl_easy_setopt(Handle, CURLOPT_SSL_VERIFYHOST, 1); // сверить имя сертификата с хостом/
   ECode:= curl_easy_setopt(Handle, CURLOPT_TIMEOUT, 5);
   ECode:= curl_easy_setopt(Handle, CURLOPT_POST, 1); // сверить имя сертификата с хостом/
   ECode:= curl_easy_setopt(Handle, CURLOPT_POSTFIELDS, PChar(urlPOST));
   ECode:= curl_easy_setopt(Handle, CURLOPT_URL, PChar(URL));
   ECode:= curl_easy_perform(Handle);
  end;
  curl_easy_cleanup(Handle);
  Terminate;
end;

constructor TCURLTest.Create(TheOwner: TComponent);
begin
  inherited Create(TheOwner);
  StopOnException:=True;
end;

destructor TCURLTest.Destroy;
begin
  inherited Destroy;
end;

var
  Application: TCURLTest;
begin
  Application:= TCURLTest.Create(nil);
  Application.Title:='cURLTest';
  Application.Run;
  Application.Free;
end.

