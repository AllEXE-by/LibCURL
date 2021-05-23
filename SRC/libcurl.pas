unit libcurl;

{╔═══════════════════════════════════════════════════════════════════════════════╗
 ║                                  _   _ ____  _                                ║
 ║                              ___| | | |  _ \| |                               ║
 ║                             / __| | | | |_) | |                               ║
 ║                            | (__| |_| |  _ <| |___                            ║
 ║                             \___|\___/|_| \_\_____|                           ║
 ║                                                                               ║
 ║           ╔═══╗╔═══╗╔═══╗     ╔╗   ╔═══╗╔════╗╔═══╗╔═══╗╔╗ ╔╗╔═══╗            ║
 ║           ║╔══╝║╔═╗║║╔═╗║     ║║   ║╔═╗║╚══╗ ║║╔═╗║║╔═╗║║║ ║║║╔═╗║            ║
 ║           ║╚══╗║║ ║║║╚═╝║     ║║   ║║ ║║  ╔╝╔╝║║ ║║║╚═╝║║║ ║║║╚══╗            ║
 ║           ║╔══╝║║ ║║║╔╗╔╝     ║║ ╔╗║╚═╝║ ╔╝╔╝ ║╚═╝║║╔╗╔╝║║ ║║╚══╗║            ║
 ║           ║║   ║╚═╝║║║║╚╗     ║╚═╝║║╔═╗║╔╝ ╚═╗║╔═╗║║║║╚╗║╚═╝║║╚═╝║            ║
 ║           ╚╝   ╚═══╝╚╝╚═╝     ╚═══╝╚╝ ╚╝╚════╝╚╝ ╚╝╚╝╚═╝╚═══╝╚═══╝            ║
 ║                                                                               ║
 ║  Copyright (C)               2021, Alexei NUZHKOV, <alexeidg@tut.by>, et al.  ║
 ║  Авторское право (С)         2021, Алексей НУЖКОВ и другие.                   ║
 ║                                                                               ║
 ║  Данное программное обеспечение лицензировано, так же как LibCURL.            ║
 ║  Условия доступны по адресу https://curl.se/docs/copyright.html.              ║
 ║                                                                               ║
 ║  Вы можете использовать, копировать, изменять, объединять, публиковать,       ║
 ║  распространять и/или продавать копии программного обеспечения                ║
 ║  в соответствии с условиями https://curl.se/docs/copyright.html.              ║
 ║                                                                               ║
 ║  Это программное обеспечение распространяется на условиях "КАК ЕСТЬ",         ║
 ║  без каких либо ГАРАНТИЙ, явных или подразумеваемых.                          ║
 ╚═══════════════════════════════════════════════════════════════════════════════╝}

{$mode objfpc}
{$MACRO on}
{$H+}
{$DEFINE CURL_NSTATIC} // СТАТИЧЕСКАЯ КОМПАНОВКА

interface

uses
{$IFDEF Unix}
  Unix
{$ENDIF}
{$IFDEF Windows}
  WinSock
{$ENDIF}
{$IFNDEF CURL_STATIC}
  , dynlibs
{$ENDIF}
;

{$IFDEF Unix}
  {$DEFINE extdecl:= cdecl}
  const LIB_CURL = 'libcurl.' + SharedSuffix;
{$ENDIF}
{$IFDEF Windows}
  {$DEFINE extdecl:= stdcall}
    {$IFDEF Win64}
      const LIB_CURL = 'libcurl-x64.' + SharedSuffix;
    {$ENDIF}
    {$IFDEF Win32}
      const LIB_CURL = 'libcurl.' + SharedSuffix;
    {$ENDIF}
{$ENDIF}

{$PACKRECORDS C}

{$i curl_types.inc}

{$IFDEF CURL_STATIC}

  // УПРАВЛЕНИЕ БИБЛИОТЕКОЙ LIBCURL
  procedure curl_global_cleanup     (); extdecl; external LIB_CURL;                                                                              // OK! Деинициализация LibCURL.
  function  curl_global_init        (const Flags: TCURLGlobalOption): TCURLCode; cdecl; external LIB_CURL;                                      // OK! Инициализация   LibCURL.
  function  curl_global_init_mem    (const Flags: TCURLGlobalOption;                                                                            //   ! Инициализация   LibCURL с обратными вызовами памяти.
                                     M: TCURL_Malloc_CallBack;
                                     F: TCURL_Free_CallBack;
                                     R: TCURL_Realloc_CallBack;
                                     S: TCURL_StrDup_CallBack;
                                     C: TCURL_Calloc_CallBack): TCURLCode; extdecl; external LIB_CURL;
  function curl_global_sslset       (ID   : TCURLSslBackEnd; Name : PChar; out Avail): TCURLSSLSet; extdecl; external LIB_CURL;                     // OK! Установка серверной части SSL для использования с LibCURL.
  function curl_version_info        (Age : TCURLVersion): TCURLVersionInfoData; extdecl; external LIB_CURL;

  // ПРОСТОЕ СОЕДИНЕНИЕ
  procedure curl_easy_cleanup       (Handle : PCURL); extdecl; external LIB_CURL;                                                                // OK! Освобождает дескриптор.
  function  curl_easy_duphandle     (Handle : PCURL): PCURL; extdecl; external LIB_CURL;                                                         // ОК! Клонирует дескриптор.
  function  curl_easy_escape        (Handle : PCURL; const Str : PChar; const Len: Integer): PChar; extdecl; external LIB_CURL;                  // OK! URL кодирует строку.
  function  curl_easy_getinfo       (Handle : PCURL; const Info: TCURLInfo; out Value): TCURLCode; extdecl; external LIB_CURL;                   // OK! Получает информацию о соединении.
  function  curl_easy_init          ()      : PCURL; extdecl; external LIB_CURL;                                                                 // OK! Инициализирует дискриптор.
  function  curl_easy_pause         (Handle : PCURL; const BitMask : TCURLPause): TCURLCode; extdecl; external LIB_CURL;                         // ОК! Приостанавливает и возобновляет соединение.
  function  curl_easy_perform       (Handle : PCURL): TCURLCode; extdecl; external LIB_CURL;                                                     // OK! Выполняет блокирующий запрос.
  function  curl_easy_recv          (Handle : PCURL; Buffer : Pointer; const BufLen : TSize; out InLen): TCURLCode; extdecl; external LIB_CURL;  //   ! Получает необработанные данные.
  procedure curl_easy_reset         (Handle : PCURL); extdecl; external LIB_CURL;                                                                // OK! Сброс всех параметров соединения.
  function  curl_easy_send          (Handle : PCURL; Buffer : Pointer; const BufLen : TSize; out OutLen): TCURLCode; extdecl; external LIB_CURL; //   ! Отправляет необработанные данные.
  function  curl_easy_setopt        (Handle : PCURL; const Option: TCURLOption): TCURLCode; varargs; extdecl; external LIB_CURL;                 // ОК! Установка параметров соединения
  function  curl_easy_strerror      (Code   : TCURLCode): PChar; extdecl; external LIB_CURL;                                                     // ОК! Возвращает описание кода ошибки
  function  curl_easy_unescape      (Handle : PCURL; Url : PChar; InLen: Integer; OutLen: PInteger): PChar; extdecl; external LIB_CURL;          // OK! Декодирует строку URL.
  function  curl_easy_unkeep        (Handle : PCURL): TCURLCode; extdecl; external LIB_CURL;                                                     // OK! Выполняет проверку состояния соединения.

  // МУЛЬТИПОТОЧНОЕ СОЕДИНЕНИЕ
  function  curl_multi_add_handle   (MultiHandle : PCURLM; Handle : PCURL): TCURLMcode; extdecl; external LIB_CURL;
  function  curl_multi_assign       (MultiHandle : PCURLM; SockFd : TCURLSocket; SockPtr : Pointer): TCURLMcode; extdecl; external LIB_CURL;
  function  curl_multi_cleanup      (MultiHandle : PCURLM): TCURLMCode; extdecl; external LIB_CURL;
  function  curl_multi_fdset        (MultiHandle : PCURLM;
                                     ReadFdSet   : PFDSet;
                                     WriteFdSet  : PFDSet;
                                     ExcFdSet    : PFDSet;
                                     MaxFd       : PInteger): TCURLMCode; extdecl; external LIB_CURL;
  function  curl_multi_info_read    (MultiHandle : PCURLM; MsgsInQueue : PInteger): PCURLMsgRec; extdecl; external LIB_CURL;
  function  curl_multi_init         ()           : PCURLM; extdecl; external LIB_CURL;
  function  curl_multi_perform      (MultiHandle : PCURLM; RunHandles : PInteger): TCURLMCode; extdecl; external LIB_CURL;
  function  curl_multi_remove_handle(MultiHandle : PCURLM; Handle : PCURL): TCURLMCode; extdecl; external LIB_CURL;
  function  curl_multi_setopt       (MultiHandle : PCURLM; Option : TCURLMOption): TCURLMCode; varargs; extdecl; external LIB_CURL;
  function  curl_multi_socket_action(MultiHandle : PCURLM; SockFd : TCURLSocket; EvBitMask : TCURLMSockAct; RunHandles : PInteger): TCURLMCode; varargs; extdecl; external LIB_CURL;
  function  curl_multi_strerror     (ErrorNum : TCURLMCode): PChar; extdecl; external LIB_CURL;
  function  curl_multi_timeout      (MultiHandle : PCURLM; TimeOut : PInt64): TCURLMCode; extdecl; external LIB_CURL;
  function  curl_multi_poll         (MultiHandle : PCURLM;
                                     ExtraFds    : PCURLWaitFdArr;
                                     ExtraNFds   : LongWord;
                                     TimeOutMs   : Integer;
                                     NumFds      : PInteger): TCURLMCode; extdecl; external LIB_CURL;
  function  curl_multi_wait         (MultiHandle : PCURLM;
                                     ExtraFds    : PCURLWaitFdArr;
                                     ExtraNFds   : LongWord;
                                     TimeOutMs   : Integer;
                                     NumFds      : PInteger): TCURLMCode; extdecl; external LIB_CURL;
  function  curl_multi_wakeup       (MultiHandle : PCURLM): TCURLMCode; extdecl; external LIB_CURL;


  // MIME
  function  curl_mime_addpart       (Mime : PCURLMime): PCURLMimePart; extdecl; external LIB_CURL;                                               //
  function  curl_mime_data          (Part : PCURLMimePart; const Data : PChar; const DataSize : TSize): TCURLCode; extdecl; external LIB_CURL;   //
  function  curl_mime_data_cb       (Part : PCURLMimePart;                                                                                       //
                                     const DataSize : TOff;                                                                                      //
                                     ReadFunc : TCURL_Read_CallBack;                                                                             //
                                     SeekFunc : TCURL_Seek_CallBack;                                                                             //
                                     FreeFunc : TCURL_Free_CallBack;                                                                             //
                                     Arg : Pointer): TCURLCode; extdecl; external LIB_CURL;                                                      //
  function  curl_mime_encoder       (Part : PCURLMimePart; const EnCoding : PChar): TCURLCode; extdecl; external LIB_CURL;                       //
  function  curl_mime_filedata      (Part : PCURLMimePart; const FileName : PChar): TCURLCode; extdecl; external LIB_CURL;                       //
  function  curl_mime_filename      (Part : PCURLMimePart; const FileName : PChar): TCURLCode; extdecl; external LIB_CURL;                       //
  procedure curl_mime_free          (Part : PCURLMimePart); extdecl; external LIB_CURL;                                                          //
  function  curl_mime_headers       (Part : PCURLMimePart; Headers : PCURLSList; const TakeOwnerShip : Integer): TCURLCode; extdecl; external LIB_CURL;//
  function  curl_mime_init          (Part : PCURL): PCURLMime; extdecl; external LIB_CURL;
  function  curl_mime_name          (Part : PCURLMimePart; const Name : PChar): TCURLCode; extdecl; external LIB_CURL;
  function  curl_mime_subparts      (Part : PCURLMimePart; SubParts : PCURLMime): TCURLCode; extdecl; external LIB_CURL;
  function  curl_mime_type          (Part : PCURLMimePart; const MimeType : PChar): TCURLCode; extdecl; external LIB_CURL;

  // ОБЩЕЕ СОЕДИНЕНИЕ
  function  curl_share_cleanup      (ShareHandle : PCURLSH): TCURLSHCode; extdecl; external LIB_CURL;
  function  curl_share_init         ()           : PCURLSH; extdecl; external LIB_CURL;
  function  curl_share_setopt       (ShareHandle : PCURLSH; const Option : TCURLSHOption): TCURLMCode; varargs; extdecl; external LIB_CURL;
  function  curl_share_strerror     (const ErrorNum : TCURLSHCode): PChar; extdecl; external LIB_CURL;

  // СПИСКИ СТРОК
  function  curl_slist_append       (List : PCURLSList; const Str : PChar): PCURLSList; extdecl; external LIB_CURL;
  function  curl_slist_free_all     (List : PCURLSList): PCURLSList; extdecl; external LIB_CURL;

  function  curl_formget            (Form : PCURLHttpPost; P : Pointer; AppEnd : TCURL_FormGet_CallBack): Integer; extdecl; external LIB_CURL;
  procedure curl_free               (P    : Pointer); extdecl; external LIB_CURL;
  function  curl_getdate            (P    : PChar; UnUsed: PTime): TTime; extdecl; external LIB_CURL;

  // ОБРАБОТКА URL
  function  curl_url                ()      : PCURLU; extdecl; external LIB_CURL;
  procedure curl_url_cleanup        (Handle : PCURLU); extdecl; external LIB_CURL;
  function  curl_url_dup            (Handle : PCURLU): PCURLU; extdecl; external LIB_CURL;
  function  curl_url_get            (Url    : PCURLU; What : TCURLUPart; Part : PPChar; Flags : LongWord): TCURLUCode; extdecl; external LIB_CURL;
  function  curl_url_set            (Url    : PCURLU; Part : TCURLUPart; Content : PChar; Flags : LongWord): TCURLUCode; extdecl; external LIB_CURL;

  // УСТАРЕВШИЕ ФУНКЦИИ
  function  curl_formadd            (Post : PPCURLHttpPost; Last_post: PPCURLHttpPost): TCURLFormCode; VarArgs; extdecl; External LIB_CURL; Deprecated;
  procedure curl_formfree           (Form : PCURLHttpPost); extdecl; External LIB_CURL; Deprecated;
  function  curl_version            (): PChar; extdecl; External LIB_CURL; Deprecated;
  function  curl_getenv             (Vars : PChar): PChar; extdecl; External LIB_CURL;  Deprecated;
  function  curl_strequal           (S1: PChar; S2: PChar): Integer; extdecl; External LIB_CURL; Deprecated;
  function  curl_strnequal          (S1: PChar; S2: PChar; N: TSize): Integer; extdecl; External LIB_CURL; Deprecated;
  function  curl_unescape           (S : PChar; Len: Integer): PChar; extdecl; External LIB_CURL; Deprecated;
  function  curl_escape             (S    : PChar; Len: Integer): Pchar; extdecl; External LIB_CURL;  Deprecated;
{$ELSE}
var
{}curl_easy_cleanup       : procedure(Handle      : PCURL); extdecl;                                                                 // OK! Освобождает дескриптор.
  curl_easy_duphandle     : function (Handle      : PCURL): PCURL; extdecl;                                                          // ОК! Клонирует дескриптор.
  curl_easy_escape        : function (Handle      : PCURL; Const Str : PChar; Const Len: Integer): PChar; extdecl;                   // OK! URL кодирует строку.
  curl_easy_getinfo       : function (Handle      : PCURL; Const Info: TCURLInfo; Out Value): TCURLCode; extdecl;                    // OK! Получает информацию о соединении.
  curl_easy_init          : function ()           : PCURL; extdecl;                                                                  // OK! Инициализация дискриптора.
  curl_easy_pause         : function (Handle      : PCURL; Const BitMask : TCURLPause): TCURLCode; extdecl;                          // ОК! Приостанавливает и возобновляет соединение.
  curl_easy_perform       : function (Handle      : PCURL): TCURLCode; extdecl;                                                      // OK! Выполняет блокирующий запрос.
  curl_easy_recv          : function (Handle      : PCURL; Buffer : Pointer; Const BufLen : TSize; Out InLen): TCURLCode; extdecl;   // NO! Получает необработанные данные.
  curl_easy_reset         : procedure(Handle      : PCURL); extdecl;                                                                 // OK! Сброс всех параметров соединения.
  curl_easy_send          : function (Handle      : PCURL; Buffer : Pointer; Const BufLen : TSize; Out OutLen): TCURLCode; extdecl;  // NO! Отправляет необработанные данные.
  curl_easy_setopt        : function (Handle      : PCURL; Const Option: TCURLOption): TCURLCode; VarArgs; extdecl;                  // ОК! Установка параметров соединения
  curl_easy_strerror      : function (const Code  : TCURLCode): PChar; extdecl;                                                      // ОК! Возвращает описание кода ошибки
  curl_easy_unescape      : function (Handle      : PCURL; Url : PChar; InLen: Integer; OutLen: PInteger): PChar; extdecl;           // OK! Декодирует строку URL.
  curl_easy_unkeep        : function (Handle      : PCURL): TCURLCode; extdecl;                                                      // OK! Выполняет проверку состояния соединения.
{}curl_global_cleanup     : procedure(); extdecl;                                                                                    // OK! Деинициализация LibCURL.
  curl_global_init        : function (const Flags : TCURLGlobalOption): TCURLCode; extdecl;                                         // OK! Инициализация LibCURL.
  curl_global_init_mem    : function (const Flags : TCURLGlobalOption;                                                              // NO! Инициализация LibCURL с обратными вызовами памяти.
                                      M           : TCURL_Malloc_CallBack;
                                      F           : TCurl_Free_CallBack;
                                      R           : TCURL_Realloc_CallBack;
                                      S           : TCURL_StrDup_CallBack;
                                      C           : TCURL_Calloc_CallBack): TCURLCode; extdecl;
  curl_global_sslset      : function (ID          : TCURLSSLBackEnd; Name : PChar; Out Avail): TCURLSSLSet; extdecl;                      // OK! Установка серверной части SSL для использования с LibCURL.
  curl_mime_addpart       : function (Mime        : PCURLMime): PCURLMimePart; extdecl;                                                //
  curl_mime_data          : function (Part        : PCURLMimePart; Const Data : PChar; Const DataSize : TSize): TCURLCode; extdecl;    //
  curl_mime_data_cb       : function (Part        : PCURLMimePart;                                                                     //
                                      DataSize    : TOff;                                                                              //
                                      ReadFunc    : TCURL_Read_CallBack;                                                               //
                                      SeekFunc    : TCURL_Seek_CallBack;                                                               //
                                      FreeFunc    : TCURL_Free_CallBack;                                                               //
                                      Arg         : Pointer): TCURLCode; extdecl;                                                      //
  curl_mime_encoder       : function (Part        : PCURLMimePart; Const EnCoding : PChar): TCURLCode; extdecl;                        //
  curl_mime_filedata      : function (Part        : PCURLMimePart; Const FileName : PChar): TCURLCode; extdecl;                        //
  curl_mime_filename      : function (Part        : PCURLMimePart; Const FileName : PChar): TCURLCode; extdecl;                        //
  curl_mime_free          : procedure(Part        : PCURLMimePart); extdecl;                                                           //
  curl_mime_headers       : function (Part        : PCURLMimePart; Headers : PCURLSList; Const TakeOwnerShip : Integer): TCURLCode; extdecl; //
  curl_mime_init          : function (Part        : PCURL): PCURLMime; extdecl;
  curl_mime_name          : function (Part        : PCURLMimePart; Const Name : PChar): TCURLCode; extdecl;
  curl_mime_subparts      : function (Part        : PCURLMimePart; SubParts : PCURLMime): TCURLCode; extdecl;
  curl_mime_type          : function (Part        : PCURLMimePart; Const MimeType : PChar): TCURLCode; extdecl;
  curl_multi_add_handle   : function (MultiHandle : PCURLM; Handle : PCURL): TCURLMcode; extdecl;
  curl_multi_assign       : function (MultiHandle : PCURLM; SockFd : TCURLSocket; SockPtr : Pointer): TCURLMcode; extdecl;
  curl_multi_cleanup      : function (MultiHandle : PCURLM): TCURLMCode; extdecl;
  curl_multi_fdset        : function (MultiHandle : PCURLM;
                                      ReadFdSet   : PFDSet;
                                      WriteFdSet  : PFDSet;
                                      ExcFdSet    : PFDSet;
                                      MaxFd       : PInteger): TCURLMCode; extdecl;
  curl_multi_info_read    : function (MultiHandle : PCURLM; MsgsInQueue : PInteger): PCURLMsgRec; extdecl;
  curl_multi_init         : function ()           : PCURLM; extdecl;
  curl_multi_perform      : function (MultiHandle : PCURLM; RunHandles : PInteger): TCURLMCode; extdecl;
  curl_multi_remove_handle: function (MultiHandle : PCURLM; Handle : PCURL): TCURLMCode; extdecl;
  curl_multi_setopt       : function (MultiHandle : PCURLM; Option : TCURLMOption): TCURLMCode; VarArgs; extdecl;
  curl_multi_socket_action: function (MultiHandle : PCURLM; SockFd : TCURLSocket; EvBitMask : TCURLMSockAct; RunHandles : PInteger): TCURLMCode; VarArgs; extdecl;
  curl_multi_strerror     : function (ErrorNum    : TCURLMCode): PChar; extdecl;
  curl_multi_timeout      : function (MultiHandle : PCURLM; TimeOut : PInt64): TCURLMCode; extdecl;
  curl_multi_poll         : function (MultiHandle : PCURLM;
                                      ExtraFds    : PCURLWaitFdArr;
                                      ExtraNFds   : LongWord;
                                      TimeOutMs   : Integer;
                                      NumFds      : PInteger): TCURLMCode; extdecl;
  curl_multi_wait         : function (MultiHandle : PCURLM;
                                      ExtraFds    : PCURLWaitFdArr;
                                      ExtraNFds   : LongWord;
                                      TimeOutMs   : Integer;
                                      NumFds      : PInteger): TCURLMCode; extdecl;
  curl_multi_wakeup       : function (MultiHandle : PCURLM): TCURLMCode; extdecl;
  curl_share_cleanup      : function (ShareHandle : PCURLSH): TCURLSHCode; extdecl;
  curl_share_init         : function ()           : PCURLSH; extdecl;
  curl_share_setopt       : function (ShareHandle : PCURLSH; Const Option : TCURLSHOption): TCURLMCode; VarArgs; extdecl;
  curl_share_strerror     : function (ErrorNum    : TCURLSHCode): PChar; extdecl;
  curl_slist_append       : function (List        : PCURLSList; Const Str : PChar): PCURLSList; extdecl;
  curl_slist_free_all     : function (List        : PCURLSList): PCURLSList; extdecl;
  curl_escape             : function (S           : PChar; Len: Integer): Pchar; extdecl;
  curl_formadd            : function (Post        : PPCURLHttpPost; Last_post: PPCURLHttpPost): TCURLFormCode; VarArgs; extdecl;
  curl_formfree           : procedure(Form        : PCURLHttpPost); extdecl;
  curl_formget            : function (Form        : PCURLHttpPost; P : Pointer; AppEnd : TCURL_FormGet_CallBack): Integer; extdecl;
  curl_free               : procedure(P           : Pointer); extdecl;
  curl_getdate            : function (P           : PChar; UnUsed: PTime): TTime; extdecl;
  curl_getenv             : function (Vars        : PChar): PChar; extdecl;
  curl_strequal           : function (S1          : PChar; S2: PChar): Integer; extdecl;
  curl_strnequal          : function (S1          : PChar; S2: PChar; N: TSize): Integer; extdecl;
  curl_unescape           : function (S           : PChar; Len: Integer): PChar; extdecl;
  curl_url                : function ()           : PCURLU; extdecl;
  curl_url_cleanup        : procedure(Handle      : PCURLU); extdecl;
  curl_url_dup            : function (Handle      : PCURLU): PCURLU; extdecl;
  curl_url_get            : function (Url         : PCURLU; What : TCURLUPart; Part : PPChar; Flags : LongWord): TCURLUCode; extdecl;
  curl_url_set            : function (Url         : PCURLU; Part : TCURLUPart; Content : PChar; Flags : LongWord): TCURLUCode; extdecl;
  curl_version            : function ()           : PChar; extdecl;
  curl_version_info       : function (Age         : TCURLVersion): TCURLVersionInfoData; extdecl;

  LibHandle : THandle;

  procedure CURLibInit;
{$ENDIF}

implementation

{$IFNDEF CURL_STATIC}
function CURLibInit;
begin
  Result:= false;
  LibHandle:= LoadLibrary(LIB_CURL);
  if LibHandle <> NilHandle then
  begin
    Pointer(curl_easy_cleanup       ):= GetProcedureAddress(LibHandle, 'curl_easy_cleanup'       );
    Pointer(curl_easy_duphandle     ):= GetProcedureAddress(LibHandle, 'curl_easy_duphandle'     );
    Pointer(curl_easy_escape        ):= GetProcedureAddress(LibHandle, 'curl_easy_escape'        );
    Pointer(curl_easy_getinfo       ):= GetProcedureAddress(LibHandle, 'curl_easy_getinfo'       );
    Pointer(curl_easy_init          ):= GetProcedureAddress(LibHandle, 'curl_easy_init'          );
    Pointer(curl_easy_pause         ):= GetProcedureAddress(LibHandle, 'curl_easy_pause'         );
    Pointer(curl_easy_perform       ):= GetProcedureAddress(LibHandle, 'curl_easy_perform'       );
    Pointer(curl_easy_recv          ):= GetProcedureAddress(LibHandle, 'curl_easy_recv'          );
    Pointer(curl_easy_reset         ):= GetProcedureAddress(LibHandle, 'curl_easy_reset'         );
    Pointer(curl_easy_send          ):= GetProcedureAddress(LibHandle, 'curl_easy_send'          );
    Pointer(curl_easy_setopt        ):= GetProcedureAddress(LibHandle, 'curl_easy_setopt'        );
    Pointer(curl_easy_strerror      ):= GetProcedureAddress(LibHandle, 'curl_easy_strerror'      );
    Pointer(curl_easy_unescape      ):= GetProcedureAddress(LibHandle, 'curl_easy_unescape'      );
    Pointer(curl_easy_unkeep        ):= GetProcedureAddress(LibHandle, 'curl_easy_unkeep'        );
    Pointer(curl_global_cleanup     ):= GetProcedureAddress(LibHandle, 'curl_global_cleanup'     );
    Pointer(curl_global_init        ):= GetProcedureAddress(LibHandle, 'curl_global_init'        );
    Pointer(curl_global_init_mem    ):= GetProcedureAddress(LibHandle, 'curl_global_init_mem'    );
    Pointer(curl_global_sslset      ):= GetProcedureAddress(LibHandle, 'curl_global_sslset'      );
    Pointer(curl_mime_addpart       ):= GetProcedureAddress(LibHandle, 'curl_mime_addpart'       );
    Pointer(curl_mime_data          ):= GetProcedureAddress(LibHandle, 'curl_mime_data'          );
    Pointer(curl_mime_data_cb       ):= GetProcedureAddress(LibHandle, 'curl_mime_data_cb'       );
    Pointer(curl_mime_encoder       ):= GetProcedureAddress(LibHandle, 'curl_mime_encoder'       );
    Pointer(curl_mime_filedata      ):= GetProcedureAddress(LibHandle, 'curl_mime_filedata'      );
    Pointer(curl_mime_filename      ):= GetProcedureAddress(LibHandle, 'curl_mime_filename'      );
    Pointer(curl_mime_free          ):= GetProcedureAddress(LibHandle, 'curl_mime_free'          );
    Pointer(curl_mime_headers       ):= GetProcedureAddress(LibHandle, 'curl_mime_headers'       );
    Pointer(curl_mime_init          ):= GetProcedureAddress(LibHandle, 'curl_mime_ini'           );
    Pointer(curl_mime_name          ):= GetProcedureAddress(LibHandle, 'curl_mime_name'          );
    Pointer(curl_mime_subparts      ):= GetProcedureAddress(LibHandle, 'curl_mime_subparts'      );
    Pointer(curl_mime_type          ):= GetProcedureAddress(LibHandle, 'curl_mime_type'          );
    Pointer(curl_multi_add_handle   ):= GetProcedureAddress(LibHandle, 'curl_multi_add_handle'   );
    Pointer(curl_multi_assign       ):= GetProcedureAddress(LibHandle, 'curl_multi_assign'       );
    Pointer(curl_multi_cleanup      ):= GetProcedureAddress(LibHandle, 'curl_multi_cleanup'      );
    Pointer(curl_multi_fdset        ):= GetProcedureAddress(LibHandle, 'curl_multi_fdset'        );
    Pointer(curl_multi_info_read    ):= GetProcedureAddress(LibHandle, 'curl_multi_info_read'    );
    Pointer(curl_multi_init         ):= GetProcedureAddress(LibHandle, 'curl_multi_init'         );
    Pointer(curl_multi_perform      ):= GetProcedureAddress(LibHandle, 'curl_multi_perform'      );
    Pointer(curl_multi_remove_handle):= GetProcedureAddress(LibHandle, 'curl_multi_remove_handle');
    Pointer(curl_multi_setopt       ):= GetProcedureAddress(LibHandle, 'curl_multi_setopt'       );
    Pointer(curl_multi_socket_action):= GetProcedureAddress(LibHandle, 'curl_multi_socket_action');
    Pointer(curl_multi_strerror     ):= GetProcedureAddress(LibHandle, 'curl_multi_strerror'     );
    Pointer(curl_multi_timeout      ):= GetProcedureAddress(LibHandle, 'curl_multi_timeout'      );
    Pointer(curl_multi_poll         ):= GetProcedureAddress(LibHandle, 'curl_multi_poll'         );
    Pointer(curl_multi_wait         ):= GetProcedureAddress(LibHandle, 'curl_multi_wait'         );
    Pointer(curl_multi_wakeup       ):= GetProcedureAddress(LibHandle, 'curl_multi_wakeup'       );
    Pointer(curl_share_cleanup      ):= GetProcedureAddress(LibHandle, 'curl_share_cleanup'      );
    Pointer(curl_share_init         ):= GetProcedureAddress(LibHandle, 'curl_share_init'         );
    Pointer(curl_share_setopt       ):= GetProcedureAddress(LibHandle, 'curl_share_setopt'       );
    Pointer(curl_share_strerror     ):= GetProcedureAddress(LibHandle, 'curl_share_strerror'     );
    Pointer(curl_slist_append       ):= GetProcedureAddress(LibHandle, 'curl_slist_append'       );
    Pointer(curl_slist_free_all     ):= GetProcedureAddress(LibHandle, 'curl_slist_free_all'     );
    Pointer(curl_escape             ):= GetProcedureAddress(LibHandle, 'curl_escape'             );
    Pointer(curl_formadd            ):= GetProcedureAddress(LibHandle, 'curl_formadd'            );
    Pointer(curl_formfree           ):= GetProcedureAddress(LibHandle, 'curl_formfree'           );
    Pointer(curl_formget            ):= GetProcedureAddress(LibHandle, 'curl_formget'            );
    Pointer(curl_free               ):= GetProcedureAddress(LibHandle, 'curl_free'               );
    Pointer(curl_getdate            ):= GetProcedureAddress(LibHandle, 'curl_getdate'            );
    Pointer(curl_getenv             ):= GetProcedureAddress(LibHandle, 'curl_getenv'             );
    Pointer(curl_strequal           ):= GetProcedureAddress(LibHandle, 'curl_strequal'           );
    Pointer(curl_strnequal          ):= GetProcedureAddress(LibHandle, 'curl_strnequal'          );
    Pointer(curl_unescape           ):= GetProcedureAddress(LibHandle, 'curl_unescape'           );
    Pointer(curl_url                ):= GetProcedureAddress(LibHandle, 'curl_url'                );
    Pointer(curl_url_cleanup        ):= GetProcedureAddress(LibHandle, 'curl_url_cleanup'        );
    Pointer(curl_url_dup            ):= GetProcedureAddress(LibHandle, 'curl_url_dup'            );
    Pointer(curl_url_get            ):= GetProcedureAddress(LibHandle, 'curl_url_get'            );
    Pointer(curl_url_set            ):= GetProcedureAddress(LibHandle, 'curl_url_set'            );
    Pointer(curl_version            ):= GetProcedureAddress(LibHandle, 'curl_version'            );
    Pointer(curl_version_info       ):= GetProcedureAddress(LibHandle, 'curl_version_info'       );
    Result:= true;
  end
  else Result:= false;
end;
{$ENDIF}

initialization
  {$IFNDEF CURL_STATIC}
    if not(CURLibInit) then Halt(1);
  {$ENDIF}
finalization
  {$IFNDEF CURL_STATIC}
    if LibHandle <> NilHandle then FreeLibrary(LibHandle);
  {$ENDIF}
end.

