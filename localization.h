#define LANGUAGE_PT_BR
// #define LANGUAGE_EN

#if defined(LANGUAGE_EN)
  #define TXT_RFID_UID "User ID:"
  #define TXT_RFID_PRESS_A_WRITE "(Press 'A' to write after reading: )"
  #define TXT_RFID_READY_READ "Ready to READ..."
  #define TXT_RFID_PRESS_A_READ "(Press 'A' to read a new card/tag: )"
  #define TXT_RFID_READY_WRITE "Ready to WRITE..."
  #define TXT_RFID_ERROR_MESSAGE "Not MIFARE Classic!"
  #define TXT_RFID_WROTE_UID "Wrote UID."
  #define TXT_RFID_FAILED_WRITE "Write failed."
#endif

#if defined(LANGUAGE_PT_BR)
  #define TXT_RFID_UID "Id do Usuario:"
  #define TXT_RFID_PRESS_A_WRITE "(Aperte 'A' para escrever depois de ler...)"
  #define TXT_RFID_READY_READ "Pronto para LER..."
  #define TXT_RFID_PRESS_A_READ "(Aperte 'A' para ler um novo cartao/tag: )"
  #define TXT_RFID_READY_WRITE "Pronto para ESCREVER..."
  #define TXT_RFID_ERROR_MESSAGE "Nao e um MIFARE Classico!"
  #define TXT_RFID_WROTE_UID "UID Escrito!"
  #define TXT_RFID_FAILED_WRITE "A escrita FALHOU!"
#endif
