// #define LANGUAGE_PT_BR
#define LANGUAGE_EN
// #define LANGUAGE_FR
// #define LANGUAGE_JP

#define TXT_RFID_UID "UID:"

#if defined(LANGUAGE_EN)
  #define TXT_RFID_PRESS_A_WRITE "(Press 'A') - WRITE MODE"
  #define TXT_RFID_PRESS_A_READ "(Press 'A') - READ MODE"
  #define TXT_RFID_ERROR_MESSAGE "Not MIFARE Classic!"
  #define TXT_RFID_WROTE_UID "Wrote UID!"
  #define TXT_RFID_FAILED_WRITE "Write failed."
#endif

#if defined(LANGUAGE_PT_BR)
  #define TXT_RFID_PRESS_A_WRITE "(Aperte 'A' )  -  MODO ESCRITA"
  #define TXT_RFID_PRESS_A_READ "(Aperte 'A') - MODO LEITURA"
  #define TXT_RFID_ERROR_MESSAGE "Nao e um MIFARE Classico!"
  #define TXT_RFID_WROTE_UID "UID gravado!"
  #define TXT_RFID_FAILED_WRITE "A escrita FALHOU!"
#endif

#if defined(LANGUAGE_FR)
  #define TXT_RFID_PRESS_A_WRITE "(Appuyez sur 'A') - MODE ÉCRITURE"
  #define TXT_RFID_PRESS_A_READ "(Appuyez sur 'A') - MODE LECTURE"
  #define TXT_RFID_ERROR_MESSAGE "Pas un MIFARE Classic!"
  #define TXT_RFID_WROTE_UID "UID écrit!"
  #define TXT_RFID_FAILED_WRITE "Écriture échouée."
#endif


#if defined(LANGUAGE_JP)
  #define TXT_RFID_PRESS_A_WRITE "('A'を押す) - 書き込みモード"
  #define TXT_RFID_PRESS_A_READ "('A'を押す) - 読み取りモード"
  #define TXT_RFID_ERROR_MESSAGE "MIFARE Classicではありません！"
  #define TXT_RFID_WROTE_UID "UIDを書き込みました！"
  #define TXT_RFID_FAILED_WRITE "書き込みに失敗しました。"
#endif
