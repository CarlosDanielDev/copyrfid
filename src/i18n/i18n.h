#define LANGUAGE_PT_BR
// #define LANGUAGE_EN

#if defined(LANGUAGE_EN)
  #define TXT_RFID_UID "UID:"
  #define TXT_RFID_PRESS_A_WRITE "(Press 'A') - WRITE MODE"
  #define TXT_RFID_PRESS_A_READ "(Press 'A') - READ MODE"
  #define TXT_RFID_ERROR_MESSAGE "Not MIFARE Classic!"
  #define TXT_RFID_WROTE_UID "Wrote UID!"
  #define TXT_RFID_FAILED_WRITE "Write failed."
#endif

#if defined(LANGUAGE_PT_BR)
  #define TXT_RFID_UID "UID:"
  #define TXT_RFID_PRESS_A_WRITE "(Aperte 'A' )  -  MODO ESCRITA"
  #define TXT_RFID_PRESS_A_READ "(Aperte 'A') - MODO LEITURA"
  #define TXT_RFID_ERROR_MESSAGE "Nao e um MIFARE Classico!"
  #define TXT_RFID_WROTE_UID "UID Escrito!"
  #define TXT_RFID_FAILED_WRITE "A escrita FALHOU!"
#endif
