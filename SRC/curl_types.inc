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
 ║  Copyright (C)        1998 - 2021, Alexei NUZHKOV, <alexeidg@tut.by>, et al.  ║
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
const
  CURLINFO_STRING                      = $100000;
  CURLINFO_LONG                        = $200000;
  CURLINFO_DOUBLE                      = $300000;
  CURLINFO_SLIST                       = $400000;
  CURLINFO_PTR                         = $400000;                          //* same as SLIST */
  CURLINFO_SOCKET                      = $500000;
  CURLINFO_OFF_T                       = $600000;
  CURLINFO_MASK                        = $0fffff;
  CURLINFO_TYPEMASK                    = $f00000;

  CURLOPTTYPE_LONG                     = 0;
  CURLOPTTYPE_OBJECTPOINT              = 10000;
  CURLOPTTYPE_FUNCTIONPOINT            = 20000;                            // Указатели на функции обратного вызова
  CURLOPTTYPE_OFF_T                    = 30000;
  CURLOPTTYPE_BLOB                     = 40000;
  CURLOPTTYPE_STRINGPOINT              = CURLOPTTYPE_OBJECTPOINT;
  CURLOPTTYPE_SLISTPOINT               = CURLOPTTYPE_OBJECTPOINT;
  CURLOPTTYPE_CBPOINT                  = CURLOPTTYPE_OBJECTPOINT;          // Указатели на структуры данных
  CURLOPTTYPE_VALUES                   = CURLOPTTYPE_LONG;


type
{EASY}
PCURLOption                            = ^TCURLOption;
TCURLOption                            =(
  CURLOPT_PORT                         = CURLOPTTYPE_LONG          + 3   , // !OK {Установить номер удаленного порта.}
  CURLOPT_TIMEOUT                      = CURLOPTTYPE_LONG          + 13  , // !OK {}
  CURLOPT_INFILESIZE                   = CURLOPTTYPE_LONG          + 14  , // !OK {}
  CURLOPT_LOW_SPEED_LIMIT              = CURLOPTTYPE_LONG          + 19  , // !OK {}
  CURLOPT_LOW_SPEED_TIME               = CURLOPTTYPE_LONG          + 20  , // !OK
  CURLOPT_RESUME_FROM                  = CURLOPTTYPE_LONG          + 21  , // !OK
  CURLOPT_CRLF                         = CURLOPTTYPE_LONG          + 27  , // !OK
  CURLOPT_SSLVERSION                   = CURLOPTTYPE_VALUES        + 32  , // !OK
  CURLOPT_TIMECONDITION                = CURLOPTTYPE_VALUES        + 33  , // !OK
  CURLOPT_TIMEVALUE                    = CURLOPTTYPE_LONG          + 34  ,
  CURLOPT_VERBOSE                      = CURLOPTTYPE_LONG          + 41  , // Показать подробную информацию.
  CURLOPT_HEADER                       = CURLOPTTYPE_LONG          + 42  , // Включите заголовок в основной вывод.
  CURLOPT_NOPROGRESS                   = CURLOPTTYPE_LONG          + 43  , // Отключите индикатор прогресса.
  CURLOPT_NOBODY                       = CURLOPTTYPE_LONG          + 44  ,
  CURLOPT_FAILONERROR                  = CURLOPTTYPE_LONG          + 45  , // Сбой при ошибках HTTP 4xx. 
  CURLOPT_UPLOAD                       = CURLOPTTYPE_LONG          + 46  ,
  CURLOPT_POST                         = CURLOPTTYPE_LONG          + 47  ,
  CURLOPT_DIRLISTONLY                  = CURLOPTTYPE_LONG          + 48  ,
  CURLOPT_APPEND                       = CURLOPTTYPE_LONG          + 50  ,
  CURLOPT_NETRC                        = CURLOPTTYPE_VALUES        + 51  ,
  CURLOPT_FOLLOWLOCATION               = CURLOPTTYPE_LONG          + 52  ,
  CURLOPT_TRANSFERTEXT                 = CURLOPTTYPE_LONG          + 53  ,
  CURLOPT_PUT                          = CURLOPTTYPE_LONG          + 54  ,
  CURLOPT_AUTOREFERER                  = CURLOPTTYPE_LONG          + 58  ,
  CURLOPT_PROXYPORT                    = CURLOPTTYPE_LONG          + 59  ,
  CURLOPT_POSTFIELDSIZE                = CURLOPTTYPE_LONG          + 60  ,
  CURLOPT_HTTPPROXYTUNNEL              = CURLOPTTYPE_LONG          + 61  ,
  CURLOPT_SSL_VERIFYPEER               = CURLOPTTYPE_LONG          + 64  ,
  CURLOPT_MAXREDIRS                    = CURLOPTTYPE_LONG          + 68  ,
  CURLOPT_FILETIME                     = CURLOPTTYPE_LONG          + 69  ,
  CURLOPT_MAXCONNECTS                  = CURLOPTTYPE_LONG          + 71  ,
  CURLOPT_OBSOLETE72                   = CURLOPTTYPE_LONG          + 72  ,
  CURLOPT_FRESH_CONNECT                = CURLOPTTYPE_LONG          + 74  ,
  CURLOPT_FORBID_REUSE                 = CURLOPTTYPE_LONG          + 75  ,
  CURLOPT_CONNECTTIMEOUT               = CURLOPTTYPE_LONG          + 78  ,
  CURLOPT_HTTPGET                      = CURLOPTTYPE_LONG          + 80  ,
  CURLOPT_SSL_VERIFYHOST               = CURLOPTTYPE_LONG          + 81  ,
  CURLOPT_HTTP_VERSION                 = CURLOPTTYPE_VALUES        + 84  ,
  CURLOPT_FTP_USE_EPSV                 = CURLOPTTYPE_LONG          + 85  ,
  CURLOPT_SSLENGINE_DEFAULT            = CURLOPTTYPE_LONG          + 90  ,
  CURLOPT_DNS_USE_GLOBAL_CACHE         = CURLOPTTYPE_LONG          + 91  ,
  CURLOPT_DNS_CACHE_TIMEOUT            = CURLOPTTYPE_LONG          + 92  ,
  CURLOPT_COOKIESESSION                = CURLOPTTYPE_LONG          + 96  ,
  CURLOPT_BUFFERSIZE                   = CURLOPTTYPE_LONG          + 98  ,
  CURLOPT_NOSIGNAL                     = CURLOPTTYPE_LONG          + 99  , // Не устанавливайте обработчики сигналов.
  CURLOPT_PROXYTYPE                    = CURLOPTTYPE_VALUES        + 101 ,
  CURLOPT_UNRESTRICTED_AUTH            = CURLOPTTYPE_LONG          + 105 ,
  CURLOPT_FTP_USE_EPRT                 = CURLOPTTYPE_LONG          + 106 ,
  CURLOPT_HTTPAUTH                     = CURLOPTTYPE_VALUES        + 107 ,
  CURLOPT_FTP_CREATE_MISSING_DIRS      = CURLOPTTYPE_LONG          + 110 ,
  CURLOPT_PROXYAUTH                    = CURLOPTTYPE_VALUES        + 111 ,
  CURLOPT_FTP_RESPONSE_TIMEOUT         = CURLOPTTYPE_LONG          + 112 ,
  CURLOPT_IPRESOLVE                    = CURLOPTTYPE_VALUES        + 113 ,
  CURLOPT_MAXFILESIZE                  = CURLOPTTYPE_LONG          + 114 ,
  CURLOPT_USE_SSL                      = CURLOPTTYPE_VALUES        + 119 ,
  CURLOPT_TCP_NODELAY                  = CURLOPTTYPE_LONG          + 121 ,
  CURLOPT_FTPSSLAUTH                   = CURLOPTTYPE_VALUES        + 129 ,
  CURLOPT_IGNORE_CONTENT_LENGTH        = CURLOPTTYPE_LONG          + 136 ,
  CURLOPT_FTP_SKIP_PASV_IP             = CURLOPTTYPE_LONG          + 137 ,
  CURLOPT_FTP_FILEMETHOD               = CURLOPTTYPE_VALUES        + 138 ,
  CURLOPT_LOCALPORT                    = CURLOPTTYPE_LONG          + 139 ,
  CURLOPT_LOCALPORTRANGE               = CURLOPTTYPE_LONG          + 140 ,
  CURLOPT_CONNECT_ONLY                 = CURLOPTTYPE_LONG          + 141 ,
  CURLOPT_SSL_SESSIONID_CACHE          = CURLOPTTYPE_LONG          + 150 ,
  CURLOPT_SSH_AUTH_TYPES               = CURLOPTTYPE_VALUES        + 151 ,
  CURLOPT_FTP_SSL_CCC                  = CURLOPTTYPE_LONG          + 154 ,
  CURLOPT_TIMEOUT_MS                   = CURLOPTTYPE_LONG          + 155 ,
  CURLOPT_CONNECTTIMEOUT_MS            = CURLOPTTYPE_LONG          + 156 ,
  CURLOPT_HTTP_TRANSFER_DECODING       = CURLOPTTYPE_LONG          + 157 ,
  CURLOPT_HTTP_CONTENT_DECODING        = CURLOPTTYPE_LONG          + 158 ,
  CURLOPT_NEW_FILE_PERMS               = CURLOPTTYPE_LONG          + 159 ,
  CURLOPT_NEW_DIRECTORY_PERMS          = CURLOPTTYPE_LONG          + 160 ,
  CURLOPT_POSTREDIR                    = CURLOPTTYPE_VALUES        + 161 ,
  CURLOPT_PROXY_TRANSFER_MODE          = CURLOPTTYPE_LONG          + 166 ,
  CURLOPT_ADDRESS_SCOPE                = CURLOPTTYPE_LONG          + 171 ,
  CURLOPT_CERTINFO                     = CURLOPTTYPE_LONG          + 172 ,
  CURLOPT_TFTP_BLKSIZE                 = CURLOPTTYPE_LONG          + 178 ,
  CURLOPT_SOCKS5_GSSAPI_NEC            = CURLOPTTYPE_LONG          + 180 ,
  CURLOPT_PROTOCOLS                    = CURLOPTTYPE_LONG          + 181 ,
  CURLOPT_REDIR_PROTOCOLS              = CURLOPTTYPE_LONG          + 182 ,
  CURLOPT_FTP_USE_PRET                 = CURLOPTTYPE_LONG          + 188 ,
  CURLOPT_RTSP_REQUEST                 = CURLOPTTYPE_VALUES        + 189 ,
  CURLOPT_RTSP_CLIENT_CSEQ             = CURLOPTTYPE_LONG          + 193 ,
  CURLOPT_RTSP_SERVER_CSEQ             = CURLOPTTYPE_LONG          + 194 ,
  CURLOPT_WILDCARDMATCH                = CURLOPTTYPE_LONG          + 197 , // Передайте несколько файлов в соответствии с шаблоном имени файла.
  CURLOPT_TRANSFER_ENCODING            = CURLOPTTYPE_LONG          + 207 ,
  CURLOPT_GSSAPI_DELEGATION            = CURLOPTTYPE_VALUES        + 210 ,
  CURLOPT_ACCEPTTIMEOUT_MS             = CURLOPTTYPE_LONG          + 212 ,
  CURLOPT_TCP_KEEPALIVE                = CURLOPTTYPE_LONG          + 213 ,
  CURLOPT_TCP_KEEPIDLE                 = CURLOPTTYPE_LONG          + 214 ,
  CURLOPT_TCP_KEEPINTVL                = CURLOPTTYPE_LONG          + 215 ,
  CURLOPT_SSL_OPTIONS                  = CURLOPTTYPE_VALUES        + 216 ,
  CURLOPT_SASL_IR                      = CURLOPTTYPE_LONG          + 218 ,
  CURLOPT_SSL_ENABLE_NPN               = CURLOPTTYPE_LONG          + 225 ,
  CURLOPT_SSL_ENABLE_ALPN              = CURLOPTTYPE_LONG          + 226 ,
  CURLOPT_EXPECT_100_TIMEOUT_MS        = CURLOPTTYPE_LONG          + 227 ,
  CURLOPT_HEADEROPT                    = CURLOPTTYPE_VALUES        + 229 ,
  CURLOPT_SSL_VERIFYSTATUS             = CURLOPTTYPE_LONG          + 232 ,
  CURLOPT_SSL_FALSESTART               = CURLOPTTYPE_LONG          + 233 ,
  CURLOPT_PATH_AS_IS                   = CURLOPTTYPE_LONG          + 234 ,
  CURLOPT_PIPEWAIT                     = CURLOPTTYPE_LONG          + 237 ,
  CURLOPT_STREAM_WEIGHT                = CURLOPTTYPE_LONG          + 239 ,
  CURLOPT_TFTP_NO_OPTIONS              = CURLOPTTYPE_LONG          + 242 ,
  CURLOPT_TCP_FASTOPEN                 = CURLOPTTYPE_LONG          + 244 ,
  CURLOPT_KEEP_SENDING_ON_ERROR        = CURLOPTTYPE_LONG          + 245 , // Продолжать отправлять по HTTP>   = 300 ошибок.
  CURLOPT_PROXY_SSL_VERIFYPEER         = CURLOPTTYPE_LONG          + 248 ,
  CURLOPT_PROXY_SSL_VERIFYHOST         = CURLOPTTYPE_LONG          + 249 ,
  CURLOPT_PROXY_SSLVERSION             = CURLOPTTYPE_VALUES        + 250 ,
  CURLOPT_PROXY_SSL_OPTIONS            = CURLOPTTYPE_LONG          + 261 ,
  CURLOPT_SUPPRESS_CONNECT_HEADERS     = CURLOPTTYPE_LONG          + 265 ,
  CURLOPT_SOCKS5_AUTH                  = CURLOPTTYPE_LONG          + 267 ,
  CURLOPT_SSH_COMPRESSION              = CURLOPTTYPE_LONG          + 268 ,
  CURLOPT_HAPPY_EYEBALLS_TIMEOUT_MS    = CURLOPTTYPE_LONG          + 271 ,
  CURLOPT_HAPROXYPROTOCOL              = CURLOPTTYPE_LONG          + 274 ,
  CURLOPT_DNS_SHUFFLE_ADDRESSES        = CURLOPTTYPE_LONG          + 275 ,
  CURLOPT_DISALLOW_USERNAME_IN_URL     = CURLOPTTYPE_LONG          + 278 ,
  CURLOPT_UPLOAD_BUFFERSIZE            = CURLOPTTYPE_LONG          + 280 ,
  CURLOPT_UPKEEP_INTERVAL_MS           = CURLOPTTYPE_LONG          + 281 ,
  CURLOPT_HTTP09_ALLOWED               = CURLOPTTYPE_LONG          + 285 ,
  CURLOPT_ALTSVC_CTRL                  = CURLOPTTYPE_LONG          + 286 ,
  CURLOPT_MAXAGE_CONN                  = CURLOPTTYPE_LONG          + 288 ,
  CURLOPT_MAIL_RCPT_ALLLOWFAILS        = CURLOPTTYPE_LONG          + 290 ,
  CURLOPT_HSTS_CTRL                    = CURLOPTTYPE_LONG          + 299 ,
  CURLOPT_DOH_SSL_VERIFYPEER           = CURLOPTTYPE_LONG          + 306 ,
  CURLOPT_DOH_SSL_VERIFYHOST           = CURLOPTTYPE_LONG          + 307 ,
  CURLOPT_DOH_SSL_VERIFYSTATUS         = CURLOPTTYPE_LONG          + 308 ,
  CURLOPT_WRITEDATA                    = CURLOPTTYPE_CBPOINT       + 1   , // Указатель данных для передачи обратному вызову записи.
  CURLOPT_URL                          = CURLOPTTYPE_STRINGPOINT   + 2   ,
  CURLOPT_PROXY                        = CURLOPTTYPE_STRINGPOINT   + 4   ,
  CURLOPT_USERPWD                      = CURLOPTTYPE_STRINGPOINT   + 5   ,
  CURLOPT_PROXYUSERPWD                 = CURLOPTTYPE_STRINGPOINT   + 6   ,
  CURLOPT_RANGE                        = CURLOPTTYPE_STRINGPOINT   + 7   ,
  CURLOPT_READDATA                     = CURLOPTTYPE_CBPOINT       + 9   , // Указатель данных для передачи обратному вызову чтения.
  CURLOPT_ERRORBUFFER                  = CURLOPTTYPE_OBJECTPOINT   + 10  , // Буфер сообщений об ошибках.
  CURLOPT_POSTFIELDS                   = CURLOPTTYPE_OBJECTPOINT   + 15  ,
  CURLOPT_REFERER                      = CURLOPTTYPE_STRINGPOINT   + 16  ,
  CURLOPT_FTPPORT                      = CURLOPTTYPE_STRINGPOINT   + 17  ,
  CURLOPT_USERAGENT                    = CURLOPTTYPE_STRINGPOINT   + 18  ,
  CURLOPT_COOKIE                       = CURLOPTTYPE_STRINGPOINT   + 22  ,
  CURLOPT_HTTPHEADER                   = CURLOPTTYPE_SLISTPOINT    + 23  ,
  CURLOPT_HTTPPOST                     = CURLOPTTYPE_OBJECTPOINT   + 24  ,
  CURLOPT_SSLCERT                      = CURLOPTTYPE_STRINGPOINT   + 25  ,
  CURLOPT_KEYPASSWD                    = CURLOPTTYPE_STRINGPOINT   + 26  ,
  CURLOPT_QUOTE                        = CURLOPTTYPE_SLISTPOINT    + 28  ,
  CURLOPT_HEADERDATA                   = CURLOPTTYPE_CBPOINT       + 29  , // Указатель данных для передачи в обратный вызов заголовка.
  CURLOPT_COOKIEFILE                   = CURLOPTTYPE_STRINGPOINT   + 31  ,
  CURLOPT_CUSTOMREQUEST                = CURLOPTTYPE_STRINGPOINT   + 36  ,
  CURLOPT_STDERR                       = CURLOPTTYPE_OBJECTPOINT   + 37  , // stderr замена потока.
  CURLOPT_POSTQUOTE                    = CURLOPTTYPE_SLISTPOINT    + 39  ,
  CURLOPT_OBSOLETE40                   = CURLOPTTYPE_OBJECTPOINT   + 40  ,
  CURLOPT_XFERINFODATA                 = CURLOPTTYPE_CBPOINT       + 57  , // Указатель данных для передачи в обратный вызов индикатора выполнения.
  CURLOPT_INTERFACE                    = CURLOPTTYPE_STRINGPOINT   + 62  ,
  CURLOPT_KRBLEVEL                     = CURLOPTTYPE_STRINGPOINT   + 63  ,
  CURLOPT_CAINFO                       = CURLOPTTYPE_STRINGPOINT   + 65  ,
  CURLOPT_TELNETOPTIONS                = CURLOPTTYPE_SLISTPOINT    + 70  ,
  CURLOPT_RANDOM_FILE                  = CURLOPTTYPE_STRINGPOINT   + 76  ,
  CURLOPT_EGDSOCKET                    = CURLOPTTYPE_STRINGPOINT   + 77  ,
  CURLOPT_COOKIEJAR                    = CURLOPTTYPE_STRINGPOINT   + 82  ,
  CURLOPT_SSL_CIPHER_LIST              = CURLOPTTYPE_STRINGPOINT   + 83  ,
  CURLOPT_SSLCERTTYPE                  = CURLOPTTYPE_STRINGPOINT   + 86  ,
  CURLOPT_SSLKEY                       = CURLOPTTYPE_STRINGPOINT   + 87  ,
  CURLOPT_SSLKEYTYPE                   = CURLOPTTYPE_STRINGPOINT   + 88  ,
  CURLOPT_SSLENGINE                    = CURLOPTTYPE_STRINGPOINT   + 89  ,
  CURLOPT_PREQUOTE                     = CURLOPTTYPE_SLISTPOINT    + 93  ,
  CURLOPT_DEBUGDATA                    = CURLOPTTYPE_CBPOINT       + 95  , // Указатель данных для передачи обратному вызову отладки.
  CURLOPT_CAPATH                       = CURLOPTTYPE_STRINGPOINT   + 97  ,
  CURLOPT_SHARE                        = CURLOPTTYPE_OBJECTPOINT   + 100 ,
  CURLOPT_ACCEPT_ENCODING              = CURLOPTTYPE_STRINGPOINT   + 102 ,
  CURLOPT_PRIVATE                      = CURLOPTTYPE_OBJECTPOINT   + 103 ,
  CURLOPT_HTTP200ALIASES               = CURLOPTTYPE_SLISTPOINT    + 104 ,
  CURLOPT_SSL_CTX_DATA                 = CURLOPTTYPE_CBPOINT       + 109 , // Указатель данных для передачи в обратный вызов контекста SSL.
  CURLOPT_NETRC_FILE                   = CURLOPTTYPE_STRINGPOINT   + 118 ,
  CURLOPT_IOCTLDATA                    = CURLOPTTYPE_CBPOINT       + 131 , // Указатель данных для передачи обратному вызову ввода-вывода.
  CURLOPT_FTP_ACCOUNT                  = CURLOPTTYPE_STRINGPOINT   + 134 ,
  CURLOPT_COOKIELIST                   = CURLOPTTYPE_STRINGPOINT   + 135 ,
  CURLOPT_FTP_ALTERNATIVE_TO_USER      = CURLOPTTYPE_STRINGPOINT   + 147 ,
  CURLOPT_SOCKOPTDATA                  = CURLOPTTYPE_CBPOINT       + 149 , // Указатель данных для передачи в обратный вызов sockopt.
  CURLOPT_SSH_PUBLIC_KEYFILE           = CURLOPTTYPE_STRINGPOINT   + 152 ,
  CURLOPT_SSH_PRIVATE_KEYFILE          = CURLOPTTYPE_STRINGPOINT   + 153 ,
  CURLOPT_SSH_HOST_PUBLIC_KEY_MD5      = CURLOPTTYPE_STRINGPOINT   + 162 ,
  CURLOPT_OPENSOCKETDATA               = CURLOPTTYPE_CBPOINT       + 164 , // Указатель данных для передачи в обратный вызов открытого сокета. 
  CURLOPT_COPYPOSTFIELDS               = CURLOPTTYPE_OBJECTPOINT   + 165 ,
  CURLOPT_SEEKDATA                     = CURLOPTTYPE_CBPOINT       + 168 , // Указатель данных для передачи обратному вызову поиска.
  CURLOPT_CRLFILE                      = CURLOPTTYPE_STRINGPOINT   + 169 ,
  CURLOPT_ISSUERCERT                   = CURLOPTTYPE_STRINGPOINT   + 170 ,
  CURLOPT_USERNAME                     = CURLOPTTYPE_STRINGPOINT   + 173 ,
  CURLOPT_PASSWORD                     = CURLOPTTYPE_STRINGPOINT   + 174 ,
  CURLOPT_PROXYUSERNAME                = CURLOPTTYPE_STRINGPOINT   + 175 ,
  CURLOPT_PROXYPASSWORD                = CURLOPTTYPE_STRINGPOINT   + 176 ,
  CURLOPT_NOPROXY                      = CURLOPTTYPE_STRINGPOINT   + 177 ,
  CURLOPT_SOCKS5_GSSAPI_SERVICE        = CURLOPTTYPE_STRINGPOINT   + 179 ,
  CURLOPT_SSH_KNOWNHOSTS               = CURLOPTTYPE_STRINGPOINT   + 183 ,
  CURLOPT_SSH_KEYDATA                  = CURLOPTTYPE_CBPOINT       + 185 ,
  CURLOPT_MAIL_FROM                    = CURLOPTTYPE_STRINGPOINT   + 186 ,
  CURLOPT_MAIL_RCPT                    = CURLOPTTYPE_SLISTPOINT    + 187 ,
  CURLOPT_RTSP_SESSION_ID              = CURLOPTTYPE_STRINGPOINT   + 190 ,
  CURLOPT_RTSP_STREAM_URI              = CURLOPTTYPE_STRINGPOINT   + 191 ,
  CURLOPT_RTSP_TRANSPORT               = CURLOPTTYPE_STRINGPOINT   + 192 ,
  CURLOPT_INTERLEAVEDATA               = CURLOPTTYPE_CBPOINT       + 195 , // Указатель данных для передачи обратному вызову чередования RTSP.
  CURLOPT_CHUNK_DATA                   = CURLOPTTYPE_CBPOINT       + 201 , // Указатель данных для передачи обратным вызовам фрагментов.
  CURLOPT_FNMATCH_DATA                 = CURLOPTTYPE_CBPOINT       + 202 , // Указатель данных для передачи в обратный вызов сопоставления с подстановочными знаками. 
  CURLOPT_RESOLVE                      = CURLOPTTYPE_SLISTPOINT    + 203 ,
  CURLOPT_TLSAUTH_USERNAME             = CURLOPTTYPE_STRINGPOINT   + 204 ,
  CURLOPT_TLSAUTH_PASSWORD             = CURLOPTTYPE_STRINGPOINT   + 205 ,
  CURLOPT_TLSAUTH_TYPE                 = CURLOPTTYPE_STRINGPOINT   + 206 ,
  CURLOPT_CLOSESOCKETDATA              = CURLOPTTYPE_CBPOINT       + 209 , // Указатель данных для передачи обратному вызову закрытого сокета.
  CURLOPT_DNS_SERVERS                  = CURLOPTTYPE_STRINGPOINT   + 211 ,
  CURLOPT_MAIL_AUTH                    = CURLOPTTYPE_STRINGPOINT   + 217 ,
  CURLOPT_XOAUTH2_BEARER               = CURLOPTTYPE_STRINGPOINT   + 220 ,
  CURLOPT_DNS_INTERFACE                = CURLOPTTYPE_STRINGPOINT   + 221 ,
  CURLOPT_DNS_LOCAL_IP4                = CURLOPTTYPE_STRINGPOINT   + 222 ,
  CURLOPT_DNS_LOCAL_IP6                = CURLOPTTYPE_STRINGPOINT   + 223 ,
  CURLOPT_LOGIN_OPTIONS                = CURLOPTTYPE_STRINGPOINT   + 224 ,
  CURLOPT_PROXYHEADER                  = CURLOPTTYPE_SLISTPOINT    + 228 ,
  CURLOPT_PINNEDPUBLICKEY              = CURLOPTTYPE_STRINGPOINT   + 230 ,
  CURLOPT_UNIX_SOCKET_PATH             = CURLOPTTYPE_STRINGPOINT   + 231 ,
  CURLOPT_PROXY_SERVICE_NAME           = CURLOPTTYPE_STRINGPOINT   + 235 ,
  CURLOPT_SERVICE_NAME                 = CURLOPTTYPE_STRINGPOINT   + 236 ,
  CURLOPT_DEFAULT_PROTOCOL             = CURLOPTTYPE_STRINGPOINT   + 238 ,
  CURLOPT_STREAM_DEPENDS               = CURLOPTTYPE_OBJECTPOINT   + 240 ,
  CURLOPT_STREAM_DEPENDS_E             = CURLOPTTYPE_OBJECTPOINT   + 241 ,
  CURLOPT_CONNECT_TO                   = CURLOPTTYPE_SLISTPOINT    + 243 ,
  CURLOPT_PROXY_CAINFO                 = CURLOPTTYPE_STRINGPOINT   + 246 ,
  CURLOPT_PROXY_CAPATH                 = CURLOPTTYPE_STRINGPOINT   + 247 ,
  CURLOPT_PROXY_TLSAUTH_USERNAME       = CURLOPTTYPE_STRINGPOINT   + 251 ,
  CURLOPT_PROXY_TLSAUTH_PASSWORD       = CURLOPTTYPE_STRINGPOINT   + 252 ,
  CURLOPT_PROXY_TLSAUTH_TYPE           = CURLOPTTYPE_STRINGPOINT   + 253 ,
  CURLOPT_PROXY_SSLCERT                = CURLOPTTYPE_STRINGPOINT   + 254 ,
  CURLOPT_PROXY_SSLCERTTYPE            = CURLOPTTYPE_STRINGPOINT   + 255 ,
  CURLOPT_PROXY_SSLKEY                 = CURLOPTTYPE_STRINGPOINT   + 256 ,
  CURLOPT_PROXY_SSLKEYTYPE             = CURLOPTTYPE_STRINGPOINT   + 257 ,
  CURLOPT_PROXY_KEYPASSWD              = CURLOPTTYPE_STRINGPOINT   + 258 ,
  CURLOPT_PROXY_SSL_CIPHER_LIST        = CURLOPTTYPE_STRINGPOINT   + 259 ,
  CURLOPT_PROXY_CRLFILE                = CURLOPTTYPE_STRINGPOINT   + 260 ,
  CURLOPT_PRE_PROXY                    = CURLOPTTYPE_STRINGPOINT   + 262 ,
  CURLOPT_PROXY_PINNEDPUBLICKEY        = CURLOPTTYPE_STRINGPOINT   + 263 ,
  CURLOPT_ABSTRACT_UNIX_SOCKET         = CURLOPTTYPE_STRINGPOINT   + 264 ,
  CURLOPT_REQUEST_TARGET               = CURLOPTTYPE_STRINGPOINT   + 266 ,
  CURLOPT_MIMEPOST                     = CURLOPTTYPE_OBJECTPOINT   + 269 ,
  CURLOPT_RESOLVER_START_DATA          = CURLOPTTYPE_CBPOINT       + 273 , // Указатель данных для передачи обратному вызову запуска резолвера.
  CURLOPT_TLS13_CIPHERS                = CURLOPTTYPE_STRINGPOINT   + 276 ,
  CURLOPT_PROXY_TLS13_CIPHERS          = CURLOPTTYPE_STRINGPOINT   + 277 ,
  CURLOPT_DOH_URL                      = CURLOPTTYPE_STRINGPOINT   + 279 ,
  CURLOPT_CURLU                        = CURLOPTTYPE_OBJECTPOINT   + 282 ,
  CURLOPT_TRAILERDATA                  = CURLOPTTYPE_CBPOINT       + 284 , // Указатель данных, передаваемый в функцию обратного вызова трейлера HTTP. 
  CURLOPT_ALTSVC                       = CURLOPTTYPE_STRINGPOINT   + 287 ,
  CURLOPT_SASL_AUTHZID                 = CURLOPTTYPE_STRINGPOINT   + 289 ,
  CURLOPT_PROXY_ISSUERCERT             = CURLOPTTYPE_STRINGPOINT   + 296 ,
  CURLOPT_SSL_EC_CURVES                = CURLOPTTYPE_STRINGPOINT   + 298 ,
  CURLOPT_HSTS                         = CURLOPTTYPE_STRINGPOINT   + 300 ,
  CURLOPT_HSTSREADDATA                 = CURLOPTTYPE_CBPOINT       + 302 , // указатель, переданный на обратный вызов чтения HSTS 
  CURLOPT_HSTSWRITEDATA                = CURLOPTTYPE_CBPOINT       + 304 , // указатель, переданный на обратный вызов записи HSTS 
  CURLOPT_AWS_SIGV4                    = CURLOPTTYPE_STRINGPOINT   + 305 ,
  CURLOPT_WRITEFUNCTION                = CURLOPTTYPE_FUNCTIONPOINT + 11  , // Обратный вызов для записи данных.
  CURLOPT_READFUNCTION                 = CURLOPTTYPE_FUNCTIONPOINT + 12  , // Обратный вызов для чтения данных.
  CURLOPT_PROGRESSFUNCTION             = CURLOPTTYPE_FUNCTIONPOINT + 56  , // УСТАРЕЛ (CURLOPT_XFERINFOFUNCTION) обратный вызов для индикатора прогресса.
  CURLOPT_HEADERFUNCTION               = CURLOPTTYPE_FUNCTIONPOINT + 79  , // Обратный вызов для записи полученных заголовков.
  CURLOPT_DEBUGFUNCTION                = CURLOPTTYPE_FUNCTIONPOINT + 94  , // Обратный звонок для получения отладочной информации.
  CURLOPT_SSL_CTX_FUNCTION             = CURLOPTTYPE_FUNCTIONPOINT + 108 , // Обратный вызов для логики контекста SSL.
  CURLOPT_IOCTLFUNCTION                = CURLOPTTYPE_FUNCTIONPOINT + 130 , // Обратный вызов для операций ввода-вывода.
  CURLOPT_CONV_FROM_NETWORK_FUNCTION   = CURLOPTTYPE_FUNCTIONPOINT + 142 , // Обратный вызов для преобразования кодовой базы.
  CURLOPT_CONV_TO_NETWORK_FUNCTION     = CURLOPTTYPE_FUNCTIONPOINT + 143 , // Обратный вызов для преобразования кодовой базы.
  CURLOPT_CONV_FROM_UTF8_FUNCTION      = CURLOPTTYPE_FUNCTIONPOINT + 144 , // Обратный вызов для преобразования кодовой базы.
  CURLOPT_SOCKOPTFUNCTION              = CURLOPTTYPE_FUNCTIONPOINT + 148 , // Обратный вызов для операций sockopt. 
  CURLOPT_OPENSOCKETFUNCTION           = CURLOPTTYPE_FUNCTIONPOINT + 163 , // Обратный вызов для создания сокета.
  CURLOPT_SEEKFUNCTION                 = CURLOPTTYPE_FUNCTIONPOINT + 167 , // Обратный вызов для операций поиска.
  CURLOPT_SSH_KEYFUNCTION              = CURLOPTTYPE_FUNCTIONPOINT + 184 , // Обратный вызов для известной логики сопоставления хостов 
  CURLOPT_INTERLEAVEFUNCTION           = CURLOPTTYPE_FUNCTIONPOINT + 196 , // Обратный вызов для данных с чередованием RTSP.
  CURLOPT_CHUNK_BGN_FUNCTION           = CURLOPTTYPE_FUNCTIONPOINT + 198 , // Обратный вызов для начала загрузки фрагмента с подстановочными знаками.
  CURLOPT_CHUNK_END_FUNCTION           = CURLOPTTYPE_FUNCTIONPOINT + 199 , // Обратный вызов для конца фрагмента загрузки с подстановочными знаками.
  CURLOPT_FNMATCH_FUNCTION             = CURLOPTTYPE_FUNCTIONPOINT + 200 , // Обратный вызов для сопоставления подстановочных знаков.
  CURLOPT_CLOSESOCKETFUNCTION          = CURLOPTTYPE_FUNCTIONPOINT + 208 , // Обратный вызов для закрытия сокета.
  CURLOPT_XFERINFOFUNCTION             = CURLOPTTYPE_FUNCTIONPOINT + 219 , // Обратный вызов функции индикатора прогресса.
  CURLOPT_RESOLVER_START_FUNCTION      = CURLOPTTYPE_FUNCTIONPOINT + 272 , // Обратный вызов вызывается перед запуском нового запроса на разрешение.
  CURLOPT_TRAILERFUNCTION              = CURLOPTTYPE_FUNCTIONPOINT + 283 , // Обратный вызов для отправки конечных заголовков
  CURLOPT_HSTSREADFUNCTION             = CURLOPTTYPE_FUNCTIONPOINT + 301 , // Обратный вызов для чтения для хостов HSTS
  CURLOPT_HSTSWRITEFUNCTION            = CURLOPTTYPE_FUNCTIONPOINT + 303 , // Обратный вызов для записи для хостов HSTS
  CURLOPT_INFILESIZE_LARGE             = CURLOPTTYPE_OFF_T         + 115 ,
  CURLOPT_RESUME_FROM_LARGE            = CURLOPTTYPE_OFF_T         + 116 ,
  CURLOPT_MAXFILESIZE_LARGE            = CURLOPTTYPE_OFF_T         + 117 ,
  CURLOPT_POSTFIELDSIZE_LARGE          = CURLOPTTYPE_OFF_T         + 120 ,
  CURLOPT_MAX_SEND_SPEED_LARGE         = CURLOPTTYPE_OFF_T         + 145 ,
  CURLOPT_MAX_RECV_SPEED_LARGE         = CURLOPTTYPE_OFF_T         + 146 ,
  CURLOPT_TIMEVALUE_LARGE              = CURLOPTTYPE_OFF_T         + 270 ,
  CURLOPT_SSLCERT_BLOB                 = CURLOPTTYPE_BLOB          + 291 ,
  CURLOPT_SSLKEY_BLOB                  = CURLOPTTYPE_BLOB          + 292 ,
  CURLOPT_PROXY_SSLCERT_BLOB           = CURLOPTTYPE_BLOB          + 293 ,
  CURLOPT_PROXY_SSLKEY_BLOB            = CURLOPTTYPE_BLOB          + 294 ,
  CURLOPT_ISSUERCERT_BLOB              = CURLOPTTYPE_BLOB          + 295 ,
  CURLOPT_PROXY_ISSUERCERT_BLOB        = CURLOPTTYPE_BLOB          + 297 ,
  CURLOPT_CAINFO_BLOB                  = CURLOPTTYPE_BLOB          + 309 ,
  CURLOPT_PROXY_CAINFO_BLOB            = CURLOPTTYPE_BLOB          + 310 ,
  CURLOPT_LASTENTRY
);
// КОДЫ ОШИБОК КУРЛА
PCURLCode                              = ^TCURLCode;
TCURLCode                              = (
  CURLE_OK                             = 0                               ,
  CURLE_UNSUPPORTED_PROTOCOL                                             ,    //* 1 */
  CURLE_FAILED_INIT                                                      ,             //* 2 */
  CURLE_URL_MALFORMAT                                                    ,           //* 3 */
  CURLE_NOT_BUILT_IN                                                     ,            //* 4 - [was obsoleted in August 2007 for
  CURLE_COULDNT_RESOLVE_PROXY                                            ,   //* 5 */
  CURLE_COULDNT_RESOLVE_HOST                                             ,    //* 6 */
  CURLE_COULDNT_CONNECT                                                  ,         //* 7 */
  CURLE_WEIRD_SERVER_REPLY                                               ,      //* 8 */
  CURLE_REMOTE_ACCESS_DENIED                                             ,    //* 9 a service was denied by the server
  CURLE_FTP_ACCEPT_FAILED                                                ,       //* 10 - [was obsoleted in April 2006 for
  CURLE_FTP_WEIRD_PASS_REPLY                                             ,   //* 11 */
  CURLE_FTP_ACCEPT_TIMEOUT                                               ,      //* 12 - timeout occurred accepting server
  CURLE_FTP_WEIRD_PASV_REPLY                                             ,    //* 13 */
  CURLE_FTP_WEIRD_227_FORMAT                                             ,    //* 14 */
  CURLE_FTP_CANT_GET_HOST                                                ,       //* 15 */
  CURLE_HTTP2                                                            ,                   //* 16 - A problem in the http2 framing layer.
  CURLE_FTP_COULDNT_SET_TYPE                                             ,    //* 17 */
  CURLE_PARTIAL_FILE                                                     ,            //* 18 */
  CURLE_FTP_COULDNT_RETR_FILE                                            ,   //* 19 */
  CURLE_OBSOLETE20                                                       ,              //* 20 - NOT USED */
  CURLE_QUOTE_ERROR                                                      ,             //* 21 - quote command failure */
  CURLE_HTTP_RETURNED_ERROR                                              ,     //* 22 */
  CURLE_WRITE_ERROR                                                      ,             //* 23 */
  CURLE_OBSOLETE24                                                       ,              //* 24 - NOT USED */
  CURLE_UPLOAD_FAILED                                                    ,           //* 25 - failed upload "command" */
  CURLE_READ_ERROR                                                       ,              //* 26 - couldn't open/read from file */
  CURLE_OUT_OF_MEMORY                                                    ,           //* 27 */
  CURLE_OPERATION_TIMEDOUT                                               ,      //* 28 - the timeout time was reached */
  CURLE_OBSOLETE29                                                       ,              //* 29 - NOT USED */
  CURLE_FTP_PORT_FAILED                                                  ,         //* 30 - FTP PORT operation failed */
  CURLE_FTP_COULDNT_USE_REST                                             ,    //* 31 - the REST command failed */
  CURLE_OBSOLETE32                                                       ,              //* 32 - NOT USED */
  CURLE_RANGE_ERROR                                                      ,             //* 33 - RANGE "command" didn't work */
  CURLE_HTTP_POST_ERROR                                                  ,         //* 34 */
  CURLE_SSL_CONNECT_ERROR                                                ,       //* 35 - wrong when connecting with SSL */
  CURLE_BAD_DOWNLOAD_RESUME                                              ,     //* 36 - couldn't resume download */
  CURLE_FILE_COULDNT_READ_FILE                                           ,  //* 37 */
  CURLE_LDAP_CANNOT_BIND                                                 ,        //* 38 */
  CURLE_LDAP_SEARCH_FAILED                                               ,      //* 39 */
  CURLE_OBSOLETE40                                                       ,              //* 40 - NOT USED */
  CURLE_FUNCTION_NOT_FOUND                                               ,      //* 41 - NOT USED starting with 7.53.0 */
  CURLE_ABORTED_BY_CALLBACK                                              ,     //* 42 */
  CURLE_BAD_FUNCTION_ARGUMENT                                            ,   //* 43 */
  CURLE_OBSOLETE44                                                       ,              //* 44 - NOT USED */
  CURLE_INTERFACE_FAILED                                                 ,        //* 45 - CURLOPT_INTERFACE failed */
  CURLE_OBSOLETE46                                                       ,              //* 46 - NOT USED */
  CURLE_TOO_MANY_REDIRECTS                                               ,      //* 47 - catch endless re-direct loops */
  CURLE_UNKNOWN_OPTION                                                   ,          //* 48 - User specified an unknown option */
  CURLE_TELNET_OPTION_SYNTAX                                             ,    //* 49 - Malformed telnet option */
  CURLE_OBSOLETE50                                                       ,              //* 50 - NOT USED */
  CURLE_OBSOLETE51                                                       ,              //* 51 - NOT USED */
  CURLE_GOT_NOTHING                                                      ,             //* 52 - when this is a specific error */
  CURLE_SSL_ENGINE_NOTFOUND                                              ,     //* 53 - SSL crypto engine not found */
  CURLE_SSL_ENGINE_SETFAILED                                             ,    //* 54 - can not set SSL crypto engine as
  CURLE_SEND_ERROR                                                       ,              //* 55 - failed sending network data */
  CURLE_RECV_ERROR                                                       ,              //* 56 - failure in receiving network data */
  CURLE_OBSOLETE57                                                       ,              //* 57 - NOT IN USE */
  CURLE_SSL_CERTPROBLEM                                                  ,         //* 58 - problem with the local certificate */
  CURLE_SSL_CIPHER                                                       ,              //* 59 - couldn't use specified cipher */
  CURLE_PEER_FAILED_VERIFICATION                                         ,//* 60 - peer's certificate or fingerprint
  CURLE_BAD_CONTENT_ENCODING                                             ,    //* 61 - Unrecognized/bad encoding */
  CURLE_LDAP_INVALID_URL                                                 ,        //* 62 - Invalid LDAP URL */
  CURLE_FILESIZE_EXCEEDED                                                ,       //* 63 - Maximum file size exceeded */
  CURLE_USE_SSL_FAILED                                                   ,          //* 64 - Requested FTP SSL level failed */
  CURLE_SEND_FAIL_REWIND                                                 ,        //* 65 - Sending the data requires a rewind
  CURLE_SSL_ENGINE_INITFAILED                                            ,   //* 66 - failed to initialise ENGINE */
  CURLE_LOGIN_DENIED                                                     ,            //* 67 - user, password or similar was not
  CURLE_TFTP_NOTFOUND                                                    ,           //* 68 - file not found on server */
  CURLE_TFTP_PERM                                                        ,               //* 69 - permission problem on server */
  CURLE_REMOTE_DISK_FULL                                                 ,        //* 70 - out of disk space on server */
  CURLE_TFTP_ILLEGAL                                                     ,            //* 71 - Illegal TFTP operation */
  CURLE_TFTP_UNKNOWNID                                                   ,          //* 72 - Unknown transfer ID */
  CURLE_REMOTE_FILE_EXISTS                                               ,      //* 73 - File already exists */
  CURLE_TFTP_NOSUCHUSER                                                  ,         //* 74 - No such user */
  CURLE_CONV_FAILED                                                      ,             //* 75 - conversion failed */
  CURLE_CONV_REQD                                                        ,               //* 76 - caller must register conversion
  CURLE_SSL_CACERT_BADFILE                                               ,      //* 77 - could not load CACERT file, missing
  CURLE_REMOTE_FILE_NOT_FOUND                                            ,   //* 78 - remote file not found */
  CURLE_SSH                                                              ,                     //* 79 - error from the SSH layer, somewhat
  CURLE_SSL_SHUTDOWN_FAILED                                              ,     //* 80 - Failed to shut down the SSL
  CURLE_AGAIN                                                            ,                   //* 81 - socket is not ready for send/recv,
  CURLE_SSL_CRL_BADFILE                                                  ,         //* 82 - could not load CRL file, missing or
  CURLE_SSL_ISSUER_ERROR                                                 ,        //* 83 - Issuer check failed.  (Added in
  CURLE_FTP_PRET_FAILED                                                  ,         //* 84 - a PRET command failed */
  CURLE_RTSP_CSEQ_ERROR                                                  ,         //* 85 - mismatch of RTSP CSeq numbers */
  CURLE_RTSP_SESSION_ERROR                                               ,      //* 86 - mismatch of RTSP Session Ids */
  CURLE_FTP_BAD_FILE_LIST                                                ,       //* 87 - unable to parse FTP file list */
  CURLE_CHUNK_FAILED                                                     ,            //* 88 - chunk callback reported error */
  CURLE_NO_CONNECTION_AVAILABLE                                          , //* 89 - No connection available, the
  CURLE_SSL_PINNEDPUBKEYNOTMATCH                                         ,//* 90 - specified pinned public key did not
  CURLE_SSL_INVALIDCERTSTATUS                                            ,   //* 91 - invalid certificate status */
  CURLE_HTTP2_STREAM                                                     ,            //* 92 - stream error in HTTP/2 framing layer
  CURLE_RECURSIVE_API_CALL                                               ,      //* 93 - an api function was called from
  CURLE_AUTH_ERROR                                                       ,              //* 94 - an authentication function returned an
  CURLE_HTTP3                                                            ,                   //* 95 - An HTTP/3 layer problem */
  CURLE_QUIC_CONNECT_ERROR                                               ,      //* 96 - QUIC connection error */
  CURLE_PROXY                                                            ,                   //* 97 - proxy handshake error */
  CURLE_SSL_CLIENTCERT                                                   ,          //* 98 - client-side certificate required */
  CURL_LAST
);







{MULTI}
// ОПЦИИ МУЛЬТИ УРЛА
PCURLMOption                           = ^TCURLMOption;
TCURLMOption                           = (
  CURLMOPT_PIPELINING                  = 3,     { 1, чтобы включить конвейерную обработку }
  CURLMOPT_MAXCONNECTS                 = 6,     { максимальное количество записей в кэше соединений }
  CURLMOPT_MAX_HOST_CONNECTIONS        = 7,     { максимальное количество конвейерных подключений к одному хосту }
  CURLMOPT_MAX_PIPELINE_LENGTH         = 8,     { максимальное количество запросов в конвейере }
  CURLMOPT_MAX_TOTAL_CONNECTIONS       = 13,    { максимальное количество открытых соединений }
  CURLMOPT_MAX_CONCURRENT_STREAMS      = 16,    { максимальное количество одновременных потоков для поддержки соединения }
  CURLMOPT_SOCKETDATA                  = 10002, { передаваемый обратному вызову сокета }
  CURLMOPT_TIMERDATA                   = 10005, { передаваемый обратному вызову таймера }
  CURLMOPT_PIPELINING_SITE_BL          = 10011, { список имен сайтов(+порт), которые заблокированы для конвейерной обработки }
  CURLMOPT_PIPELINING_SERVER_BL        = 10012, { список типов серверов, которые заблокированы для конвейерной обработки }
  CURLMOPT_PUSHDATA                    = 10015, { передаваемый серверу push-обратного вызова }
  CURLMOPT_SOCKETFUNCTION              = 20001, { указатель функции обратного вызова сокета }
  CURLMOPT_TIMERFUNCTION               = 20004, { указатель функции обратного вызова таймера }
  CURLMOPT_PUSHFUNCTION                = 20014, { указатель функции обратного вызова сервера push }
  CURLMOPT_CONTENT_LENGTH_PENALTY_SIZE = 30009, { соединение с длиной содержимого больше этой длины не будет рассматриваться для конвейерной обработки }
  CURLMOPT_CHUNK_LENGTH_PENALTY_SIZE   = 30010, { соединение с длиной блока больше этой длины не будет рассматриваться для конвейерной обработки }
  CURLMOPT_LASTENTRY
);
// КОДЫ ОШИБОК МУЛЬТИ УРЛА
PCURLMCode                             = ^TCURLMCode;
TCURLMCode                             = (
  CURLM_CALL_MULTI_PERFORM             = -1, { выполните curl_multi_perform() или curl_multi_socket*() }
  CURLM_OK                             = 0,                // Без ошибок.
  CURLM_BAD_HANDLE,            //* the passed-in handle is not a valid CURLM handle */
  CURLM_BAD_EASY_HANDLE,       //* an easy handle was not good/valid */
  CURLM_OUT_OF_MEMORY,         //* if you ever get this, you're in deep sh*t */
  CURLM_INTERNAL_ERROR,        //* this is a libcurl bug */
  CURLM_BAD_SOCKET,            //* the passed in socket argument did not match */
  CURLM_UNKNOWN_OPTION,        //* curl_multi_setopt() with unsupported option */
  CURLM_ADDED_ALREADY,         //* an easy handle already added to a multi handle was attempted to get added - again */
  CURLM_RECURSIVE_API_CALL,    //* an api function was called from inside a callback */
  CURLM_WAKEUP_FAILURE,        //* wakeup is unavailable or failed */
  CURLM_BAD_FUNCTION_ARGUMENT, //* function called with a bad parameter */
  CURLM_LAST
);
{MULTI}



  // ОПЦИИ ИНФОРМАЦИИ О СОЕДИНЕНИИ
PCURLInfo                              = ^TCURLInfo;
TCURLInfo                              = ( //
  CURLINFO_NONE                        = 0                              ,
  CURLINFO_LASTONE                     = 60                             ,
  CURLINFO_EFFECTIVE_URL               = CURLINFO_STRING           + 1  , //
  CURLINFO_CONTENT_TYPE                = CURLINFO_STRING           + 18 , //
  CURLINFO_PRIVATE                     = CURLINFO_STRING           + 21 , //
  CURLINFO_FTP_ENTRY_PATH              = CURLINFO_STRING           + 30 , //
  CURLINFO_REDIRECT_URL                = CURLINFO_STRING           + 31 , //
  CURLINFO_PRIMARY_IP                  = CURLINFO_STRING           + 32 , //
  CURLINFO_RTSP_SESSION_ID             = CURLINFO_STRING           + 36 , //
  CURLINFO_LOCAL_IP                    = CURLINFO_STRING           + 41 , //
  CURLINFO_SCHEME                      = CURLINFO_STRING           + 49 , //
  CURLINFO_EFFECTIVE_METHOD            = CURLINFO_STRING           + 58 , //
  CURLINFO_REFERER                     = CURLINFO_STRING           + 60 , //
  CURLINFO_RESPONSE_CODE               = CURLINFO_LONG             + 2  , //
  CURLINFO_HEADER_SIZE                 = CURLINFO_LONG             + 11 , //
  CURLINFO_REQUEST_SIZE                = CURLINFO_LONG             + 12 , //
  CURLINFO_SSL_VERIFYRESULT            = CURLINFO_LONG             + 13 , //
  CURLINFO_FILETIME                    = CURLINFO_LONG             + 14 , //
  CURLINFO_REDIRECT_COUNT              = CURLINFO_LONG             + 20 , //
  CURLINFO_HTTP_CONNECTCODE            = CURLINFO_LONG             + 22 , //
  CURLINFO_HTTPAUTH_AVAIL              = CURLINFO_LONG             + 23 , //
  CURLINFO_PROXYAUTH_AVAIL             = CURLINFO_LONG             + 24 , //
  CURLINFO_OS_ERRNO                    = CURLINFO_LONG             + 25 , //
  CURLINFO_NUM_CONNECTS                = CURLINFO_LONG             + 26 , //
  CURLINFO_LASTSOCKET                  = CURLINFO_LONG             + 29 , //
  CURLINFO_CONDITION_UNMET             = CURLINFO_LONG             + 35 , //
  CURLINFO_RTSP_CLIENT_CSEQ            = CURLINFO_LONG             + 37 , //
  CURLINFO_RTSP_SERVER_CSEQ            = CURLINFO_LONG             + 38 , //
  CURLINFO_RTSP_CSEQ_RECV              = CURLINFO_LONG             + 39 , //
  CURLINFO_PRIMARY_PORT                = CURLINFO_LONG             + 40 , //
  CURLINFO_LOCAL_PORT                  = CURLINFO_LONG             + 42 , //
  CURLINFO_HTTP_VERSION                = CURLINFO_LONG             + 46 , //
  CURLINFO_PROXY_SSL_VERIFYRESULT      = CURLINFO_LONG             + 47 , //
  CURLINFO_PROTOCOL                    = CURLINFO_LONG             + 48 , //
  CURLINFO_PROXY_ERROR                 = CURLINFO_LONG             + 59 , //
  CURLINFO_TOTAL_TIME                  = CURLINFO_DOUBLE           + 3  , //
  CURLINFO_NAMELOOKUP_TIME             = CURLINFO_DOUBLE           + 4  , //
  CURLINFO_CONNECT_TIME                = CURLINFO_DOUBLE           + 5  , //
  CURLINFO_PRETRANSFER_TIME            = CURLINFO_DOUBLE           + 6  , //
  CURLINFO_SIZE_UPLOAD                 = CURLINFO_DOUBLE           + 7  , //
  CURLINFO_SIZE_DOWNLOAD               = CURLINFO_DOUBLE           + 8  , //
  CURLINFO_SPEED_DOWNLOAD              = CURLINFO_DOUBLE           + 9  , //
  CURLINFO_SPEED_UPLOAD                = CURLINFO_DOUBLE           + 10 , //
  CURLINFO_CONTENT_LENGTH_DOWNLOAD     = CURLINFO_DOUBLE           + 15 , //
  CURLINFO_CONTENT_LENGTH_UPLOAD       = CURLINFO_DOUBLE           + 16 , //
  CURLINFO_STARTTRANSFER_TIME          = CURLINFO_DOUBLE           + 17 , //
  CURLINFO_REDIRECT_TIME               = CURLINFO_DOUBLE           + 19 , //
  CURLINFO_APPCONNECT_TIME             = CURLINFO_DOUBLE           + 33 , //
  CURLINFO_SSL_ENGINES                 = CURLINFO_SLIST            + 27 , //
  CURLINFO_COOKIELIST                  = CURLINFO_SLIST            + 28 , //
  CURLINFO_CERTINFO                    = CURLINFO_PTR              + 34 , //
  CURLINFO_TLS_SESSION                 = CURLINFO_PTR              + 43 , //
  CURLINFO_TLS_SSL_PTR                 = CURLINFO_PTR              + 45 , //
  CURLINFO_ACTIVESOCKET                = CURLINFO_SOCKET           + 44 , //
  CURLINFO_SIZE_UPLOAD_T               = CURLINFO_OFF_T            + 7  , //
  CURLINFO_SIZE_DOWNLOAD_T             = CURLINFO_OFF_T            + 8  , //
  CURLINFO_SPEED_DOWNLOAD_T            = CURLINFO_OFF_T            + 9  , //
  CURLINFO_SPEED_UPLOAD_T              = CURLINFO_OFF_T            + 10 , //
  CURLINFO_FILETIME_T                  = CURLINFO_OFF_T            + 14 , //
  CURLINFO_CONTENT_LENGTH_DOWNLOAD_T   = CURLINFO_OFF_T            + 15 , //
  CURLINFO_CONTENT_LENGTH_UPLOAD_T     = CURLINFO_OFF_T            + 16 , //
  CURLINFO_TOTAL_TIME_T                = CURLINFO_OFF_T            + 50 , //
  CURLINFO_NAMELOOKUP_TIME_T           = CURLINFO_OFF_T            + 51 , //
  CURLINFO_CONNECT_TIME_T              = CURLINFO_OFF_T            + 52 , //
  CURLINFO_PRETRANSFER_TIME_T          = CURLINFO_OFF_T            + 53 , //
  CURLINFO_STARTTRANSFER_TIME_T        = CURLINFO_OFF_T            + 54 , //
  CURLINFO_REDIRECT_TIME_T             = CURLINFO_OFF_T            + 55 , //
  CURLINFO_APPCONNECT_TIME_T           = CURLINFO_OFF_T            + 56 , //
  CURLINFO_RETRY_AFTER                 = CURLINFO_OFF_T            + 57   //
);

  // КОДЫ ОШИБОК УРЛА
PCURLUCode                             = ^TCURLUCode;
TCURLUCode                             = (
  CURLUE_OK                            = 0                              ,
  CURLUE_BAD_HANDLE                                                     ,          //* 1 */
  CURLUE_BAD_PARTPOINTER                                                ,     //* 2 */
  CURLUE_MALFORMED_INPUT                                                ,     //* 3 */
  CURLUE_BAD_PORT_NUMBER                                                ,     //* 4 */
  CURLUE_UNSUPPORTED_SCHEME                                             ,  //* 5 */
  CURLUE_URLDECODE                                                      ,           //* 6 */
  CURLUE_OUT_OF_MEMORY                                                  ,       //* 7 */
  CURLUE_USER_NOT_ALLOWED                                               ,    //* 8 */
  CURLUE_UNKNOWN_PART                                                   ,        //* 9 */
  CURLUE_NO_SCHEME                                                      ,           //* 10 */
  CURLUE_NO_USER                                                        ,             //* 11 */
  CURLUE_NO_PASSWORD                                                    ,         //* 12 */
  CURLUE_NO_OPTIONS                                                     ,          //* 13 */
  CURLUE_NO_HOST                                                        ,             //* 14 */
  CURLUE_NO_PORT                                                        ,             //* 15 */
  CURLUE_NO_QUERY                                                       ,            //* 16 */
  CURLUE_NO_FRAGMENT          //* 17 */
);

PCURLUPart = ^TCURLUPart;
TCURLUPart = (
  CURLUPART_URL,
  CURLUPART_SCHEME,
  CURLUPART_USER,
  CURLUPART_PASSWORD,
  CURLUPART_OPTIONS,
  CURLUPART_HOST,
  CURLUPART_PORT,
  CURLUPART_PATH,
  CURLUPART_QUERY,
  CURLUPART_FRAGMENT,
  CURLUPART_ZONEID //* added in 7.65.0 */
);

PCURLSHCode = ^TCURLSHCode;
TCURLSHCode = (
  CURLSHE_OK = 0,
  CURLSHE_BAD_OPTION,
  CURLSHE_IN_USE,
  CURLSHE_INVALID,
  CURLSHE_NOMEM,
  CURLSHE_LAST
);

PCURLSHOption = ^TCURLSHOption;
TCURLSHOption = (
  CURLSHOPT_NONE = 0,
  CURLSHOPT_SHARE,
  CURLSHOPT_UNSHARE,
  CURLSHOPT_LOCKFUNC,
  CURLSHOPT_UNLOCKFUNC,
  CURLSHOPT_USERDATA,
  CURLSHOPT_LAST
);

TCURLIOErr = (
  CURLIOE_OK = 0,
  CURLIOE_UNKNOWNCMD,
  CURLIOE_FAILRESTART,
  CURLIOE_LAST
);

TCURLInfoType = (
  CURLINFO_TEXT = 0,
  CURLINFO_HEADER_IN,
  CURLINFO_HEADER_OUT,
  CURLINFO_DATA_IN,
  CURLINFO_DATA_OUT,
  CURLINFO_SSL_DATA_IN,
  CURLINFO_SSL_DATA_OUT,
  CURLINFO_END
);

TCURLLockData = (
  CURL_LOCK_DATA_NONE = 0,
  CURL_LOCK_DATA_SHARE,
  CURL_LOCK_DATA_COOKIE,
  CURL_LOCK_DATA_DNS,
  CURL_LOCK_DATA_SSL_SESSION,
  CURL_LOCK_DATA_CONNECT,
  CURL_LOCK_DATA_LAST
);

TCURLLockAccess = (
  CURL_LOCK_ACCESS_NONE   = 0,
  CURL_LOCK_ACCESS_SHARED = 1,
  CURL_LOCK_ACCESS_SINGLE = 2,
  CURL_LOCK_ACCESS_LAST
);

TCURLVersion = (
  CURLVERSION_FIRST,
  CURLVERSION_SECOND,
  CURLVERSION_THIRD,
  CURLVERSION_LAST
);

TCURLMsg = (
  CURLMSG_NONE,
  CURLMSG_DONE,
  CURLMSG_LAST
);

TCURLFormCode = (
  CURL_FORMADD_OK = 0,
  CURL_FORMADD_MEMORY,
  CURL_FORMADD_OPTION_TWICE,
  CURL_FORMADD_NULL,
  CURL_FORMADD_UNKNOWN_OPTION,
  CURL_FORMADD_INCOMPLETE,
  CURL_FORMADD_ILLEGAL_ARRAY,
  CURL_FORMADD_DISABLED,
  CURL_FORMADD_LAST
);

{GLOBAL}
// ОПЦИИ ИНИЦИАЛИЗАЦИИ БИБЛИОТЕКИ ЛИБУРЛ
PCURLGlobalOption = ^TCURLGlobalOption;
TCURLGlobalOption                = (
  CURL_GLOBAL_NOTHING            = 0,
  CURL_GLOBAL_SSL,                       { no purpose since since 7.57.0 }
  CURL_GLOBAL_WIN32,
  CURL_GLOBAL_ALL,
  CURL_GLOBAL_ACK_EINTR
  );
// ОПЦИИ НАСТРОЙКИ СЕРВЕРА SSL
TCURLSSLBackEnd                  = (
  CURLSSLBACKEND_NONE            = 0,            // !OK
  CURLSSLBACKEND_OPENSSL         = 1,            // !OK
  CURLSSLBACKEND_GNUTLS          = 2,            // !OK
  CURLSSLBACKEND_NSS             = 3,            // !OK
  CURLSSLBACKEND_OBSOLETE4       = 4,            // !OK  Was QSOSSL.
  CURLSSLBACKEND_GSKIT           = 5,            // !OK
  CURLSSLBACKEND_POLARSSL        = 6,            // !OK
  CURLSSLBACKEND_WOLFSSL         = 7,            // !OK
  CURLSSLBACKEND_SCHANNEL        = 8,            // !OK
  CURLSSLBACKEND_SECURETRANSPORT = 9,            // !OK
  CURLSSLBACKEND_AXTLS           = 10,           // !OK  never used since 7.63.0
  CURLSSLBACKEND_MBEDTLS         = 11,           // !OK
  CURLSSLBACKEND_MESALINK        = 12,           // !OK
  CURLSSLBACKEND_BEARSSL         = 13,           // !OK
  CURLSSLBACKEND_RUSTLS          = 14            // !OK
  );
// РЕЗУЛЬТАТ НАСТРОЙКИ СЕРВЕРА SSL
TCURLSSLSet                      = (
  CURLSSLSET_OK                  = 0,            // !OK серверная часть была успешно выбрана.
  CURLSSLSET_UNKNOWN_BACKEND,                    // !OK если указанный бэкэнд SSL недоступен
  CURLSSLSET_TOO_LATE,                           // !OK Серверную часть SSL можно установить только один раз. Если он уже был установлен, последующая попытка изменить его приведет к
  CURLSSLSET_NO_BACKENDS                         // !OK libcurl был построен без какой-либо поддержки SSL
);
// АЛЬТЕРНАТИВНАЯ ЗАПИСЬ И СПИСОК SSL
PCURLSslBackEndRec = ^TCURLSslBackEndRec;        // !OK;
TCURLSslBackEndArr = Array of PCURLSslBackEndRec;// !OK
TCURLSSLBackEndRec = record                      // !OK
  id   : TCURLSSLBackEnd;                        // !OK
  name : PChar;                                  // !OK
end;
{GLOBAL}




  // ОПЦИИ ПАУЗЫ СОЕДИНЕНИЯ
TCURLPause = (
  CURLPAUSE_CONT = 0,
  CURLPAUSE_RECV,
  CURLPAUSE_SEND,
  CURLPAUSE_ALL);

TCURLMSockAct = (
  CURL_CSELECT_IN  = 1,
  CURL_CSELECT_OUT = 2,
  CURL_CSELECT_ALL = 3,
  CURL_CSELECT_ERR = 4);

PTime         = ^TTime;

TCURL         = Pointer;
PCURL         = ^TCURL;

TCURLHandle   = ^TCURL;

TCURLSH       = Pointer;
PCURLSH       = ^TCURLSH;

TCURLM        = Pointer;
PCURLM        = ^TCURLM;

TCURLU        = Pointer;
PCURLU        = ^TCURLU;

TCURLMimePart = Pointer;
PCURLMimePart = ^TCURLMimePart;

TCURLMime     = Pointer;
PCURLMime     = ^TCURLMime;

{$IFDEF Unix}

{$ifdef cpu64}
  TCURLSocket   = QWord;
{$else}
  TCURLSocket   = DWord;
{$endif}

FdSet = record
  Fd_Count : DWord;
  Fd_Array : Array[0..63] of TCURLSocket;
end;

TFdSet = FdSet;
PFdSet = ^FdSet;

{$ENDIF}
{$IFDEF Windows}
  {$ifdef cpu64}
    TSize = QWord;
    TOff  = Int64;
  {$else}
    TSize = DWord;
    TOff  = Int32;
  {$endif}
    PSize = ^TSize;
    POff  = ^TOff;
    TCURLSocket   = TSocket;
{$ENDIF}

TCURL_Malloc_CallBack   = procedure(Size : TSize); extdecl;
TCURL_Realloc_CallBack  = procedure(Ptr : Pointer; Size : TSize); extdecl;
TCURL_StrDup_CallBack   = function (Str : PChar): PChar; extdecl;
TCURL_Calloc_CallBack   = procedure(NMemb : TSize; Size : TSize); extdecl;
TCURL_Seek_CallBack     = function (Arg : Pointer; OffSet : Integer; Origin : Integer): Integer; extdecl;
TCURL_Free_CallBack     = procedure(Ptr: Pointer); extdecl;
TCURL_FormGet_CallBack  = function (UserP : Pointer; Buff : PChar; Len : TSize): PSize; extdecl;

TCURL_Write_CallBack    = function (Buffer: PChar; Size: TSize; Count: TSize; Stream: Pointer): TSize; extdecl;
TCURL_Read_CallBack     = function (Buffer: PChar; Size: TSize; Count: TSize; Stream: Pointer): TSize; extdecl;


TCURLWaitFd  = record
  Fd      : TCURLSocket;
  Events  : SmallInt;
  Revents : SmallInt;
end;

PCURLWaitFdArr = ^TCURLWaitFdArr;
TCURLWaitFdArr = Array of TCURLWaitFd;

PCURLSList = ^TCURLSList;
TCURLSList = record
  Data: PChar;
  Next: PCURLSList;
end;

PCURLHttpPost = ^TCURLHttpPost;
PPCURLHttpPost = ^PCURLHttpPost;
TCURLHttpPost = record
  Next: PCURLHttpPost;
  Name: PChar;
  Namelength: Integer;
  Contents: PChar;
  Contentslength: Integer;
  Buffer: PChar;
  Bufferlength: Integer;
  Contenttype: PChar;
  Contentheader: PCURLSList;
  More: PCURLHttpPost;
  Flags: Integer;
  Showfilename: PChar;
end;

TCURLVersionInfoData = record
  Age : TCURLversion ;          //* age of the returned struct */
  Version : PChar;              //* LIBCURL_VERSION */
  VersionNum : LongWord;        //* LIBCURL_VERSION_NUM */
  Host : PChar;                 //* OS/host/cpu/machine when configured */
  Features : LongInt;           //* bitmask, see defines below */
  SslVersion : PChar;           //* human readable string */
  SslVersionNum : LongInt;      //* not used anymore, always 0 */
  LibzVersion : PChar;          //* human readable string */  //* protocols is terminated by an entry with a NULL protoname */
  Protocols : PChar;            //* The fields below this were added in CURLVERSION_SECOND */
  Ares : PChar;
  Ares_Num : LongInt;           //* This field was added in CURLVERSION_THIRD */
  LibIdn : PChar;               //* These field were added in CURLVERSION_FOURTH */ //* Same as '_libiconv_version' if built with HAVE_ICONV */
  IconvVerNum : LongInt;
  LibSshVersion : PChar;        //* human readable string */   //* These fields were added in CURLVERSION_FIFTH */
  BrotliVerNum : Cardinal;      //* Numeric Brotli version (MAJOR << 24) | (MINOR << 12) | PATCH */
  BrotliVersion : PChar;        //* human readable string. */   //* These fields were added in CURLVERSION_SIXTH */
  NgHttp2VerNum : LongWord;     //* Numeric nghttp2 version (MAJOR << 16) | (MINOR << 8) | PATCH */
  NgHttp2Version : PChar;       //* human readable string. */
  QuicVersion : PChar;          //* human readable quic (+ HTTP/3) library + version or NULL */   //* These fields were added in CURLVERSION_SEVENTH */
  CaInfo : PChar;               //* the built-in default CURLOPT_CAINFO, might be NULL */
  CaPath : PChar;               //* the built-in default CURLOPT_CAPATH, might be NULL */   //* These fields were added in CURLVERSION_EIGHTH */
  ZstdVerNum : LongWord;        //* Numeric Zstd version  (MAJOR << 24) | (MINOR << 12) | PATCH */
  ZstdVersion: PChar;           //* human readable string.  These fields were added in CURLVERSION_NINTH */
  HyperVersion : PChar;         //* human readable string. 
end;

PCURLMsgRec = ^TCurlMsgRec;
TCURLMsgRec = record
  Msg: TCURLMsg;
  Easy_handle: PCURL;
  Data: record case Integer of 0: (Whatever: Pointer);
  1: (Result: TCURLCode);
end;

end;

