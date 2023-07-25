/*
 * NOME: ADENILTO RIBEIRO
 * DATA: 24/07/2023
 * PROJETO: ESP32 FIREBASE
 * VERSAO: 01
 * DESCRICAO: - EXEMPLO DE FUNÇÃO GET. EXEMPLO DE FUNÇÃO SET. EXEMPLO DE PUSH. 
 * LINK: - https://github.com/mobizt/Firebase-ESP32
*/

// ========================================================================================================
//---BIBLIOTECAS AUXILIARES---

#include <Arduino.h>
#ifdef ESP8266 
  #include <ESP8266WiFi.h>
  #include "FirebaseESP8266.h" // https://github.com/mobizt/Firebase-ESP8266
#endif 
#ifdef ESP32   
  #include <WiFi.h>
  #include <FirebaseESP32.h>   // https://github.com/mobizt/Firebase-ESP32
#endif
// ========================================================================================================

// ========================================================================================================
//---MAPEAMENTO DE ESTADO---

/** @brief Velocidade do baud rade */
#define BAUD_RATE                115200
/** @brief Nome da rede WI-FI */
const char* ssid =               "nome-da-sua-rede-wi-fi";
/** @brief Nome da senha */
const char* password =           "senha";

//---configurações de firebase--- 
/** @brief Link do seu banco de dados */                  
#define FIREBASE_HOST            "link-do-seu-banco-de-dados-firebase" 
/** @brief Senha do seu banco de dados */
#define FIREBASE_AUTH            "senha-do-seu-banco-de-dados"  
/** @brief Configurações do ID Firebase */
#define ID_para_teste_inovacao   "/inovacao_teste/teste_1/estado"           
// ========================================================================================================

// ========================================================================================================

//---MAPEAMENTO DE HARDWARE---
// ========================================================================================================

// ========================================================================================================
//---VARIAVEIS GLOBAIS---

/** @brief Defina o número da porta do servidor web para 80 */
WiFiServer server(80);
/** @brief Verificação de conexão */
boolean wifi_conexao = false;

//---variavel de leitura do ID firebase---
bool estado_bool;
int estado_int;
float estado_float;
String estado_string = "";

/** @brief Delay */
unsigned long tempo_anterior_1  = 0;
/** @brief Contador para debug */
int cont = 0;
// ========================================================================================================

// ========================================================================================================
//---PROTOTIPO DA FUNCAO---

boolean CONECT_WIFI();
void VERIFICACAO_WIFI();
void GET_FIREBASE();
void SET_FIREBASE();
void PUSH_FIREBASE();
void SETUP_FIREBASE();
// ========================================================================================================

// ========================================================================================================
//---CONFIGURAÇÃO FIREBASE---

/** @brief Cria um objeto*/
FirebaseData firebaseData;
// ========================================================================================================

// ========================================================================================================
/**
 * @brief Void setup
 * 
 */
void setup() {
  Serial.begin(BAUD_RATE); 

//---verificação do wifi, essa função pose ser usado ou não---
  CONECT_WIFI();
  VERIFICACAO_WIFI();

  SETUP_FIREBASE();
}
// ========================================================================================================

// ========================================================================================================
/**
 * @brief Void loop
 * 
 */
void loop() {
  delay(1);
//---verificar conexão de wi-fi, 3 - conectado, 6 - sem conexão---
  //Serial.println(WiFi.status());

//---verificar conexão de wi-fi---
  if(WiFi.status() != WL_CONNECTED) {
    delay(100);
    CONECT_WIFI();
  }

//---descomentar para sua aplicação---
  //GET_FIREBASE();
  SET_FIREBASE();
  //PUSH_FIREBASE();
}
// ========================================================================================================

// ========================================================================================================
/**
 * @brief Obter o objeto firebase
 * 
 * @note Descomentar qual tipo de variável você quer usar
 */
void GET_FIREBASE() {
//---exemplo da função Get lé os dados do firebase---

//---bool (sem condição de tempo)---
  // Firebase.getBool(firebaseData, ID_para_teste_inovacao);
  // estado_bool = firebaseData.boolData();
  // Serial.println(firebaseData.boolData());
  // delay(150);

//---bool (com condição de tempo)---
  // if(Firebase.ready() && (millis() - tempo_anterior_1 > 150 || tempo_anterior_1 == 0)){
  //   tempo_anterior_1 = millis();
    
  //   if(Firebase.getBool(firebaseData, ID_para_teste_inovacao)) {
  //     //estado_bool = firebaseData.boolData();
  //     Serial.println(firebaseData.boolData());
  //   }else{
  //     Serial.println(firebaseData.errorReason());
  //   }
  // }

//---int (sem condição de tempo)---
  // Firebase.getInt(firebaseData, ID_para_teste_inovacao);
  // estado_int = firebaseData.intData();
  // Serial.println(firebaseData.intData());
  // delay(150);

//---int (com condição de tempo)---
  // if(Firebase.ready() && (millis() - tempo_anterior_1 > 150 || tempo_anterior_1 == 0)){
  //   tempo_anterior_1 = millis();
    
  //   if(Firebase.getInt(firebaseData, ID_para_teste_inovacao)) {
  //     //estado_int = firebaseData.intData();
  //     Serial.println(firebaseData.intData());
  //   }else{
  //     Serial.println(firebaseData.errorReason());
  //   }
  // }

//---float (sem condição de tempo)---
  // Firebase.getFloat(firebaseData, ID_para_teste_inovacao);
  // estado_float = firebaseData.floatData();
  // Serial.println(firebaseData.floatData());
  // delay(150);

//---float (com condição de tempo)---
  // if(Firebase.ready() && (millis() - tempo_anterior_1 > 150 || tempo_anterior_1 == 0)){
  //   tempo_anterior_1 = millis();
    
  //   if(Firebase.getFloat(firebaseData, ID_para_teste_inovacao)) {
  //     //estado_float = firebaseData.floatData();
  //     Serial.println(firebaseData.floatData());
  //   }else{
  //     Serial.println(firebaseData.errorReason());
  //   }
  // }

//---string (sem condição de tempo)---
  // Firebase.getString(firebaseData, ID_para_teste_inovacao);
  // estado_string = firebaseData.stringData();
  // Serial.println(firebaseData.stringData());
  // delay(150);

//---string (com condição de tempo)---
  if(Firebase.ready() && (millis() - tempo_anterior_1 > 150 || tempo_anterior_1 == 0)){
    tempo_anterior_1 = millis();
    
    if(Firebase.getString(firebaseData, ID_para_teste_inovacao)) {
      //estado_string = firebaseData.stringData();
      Serial.println(firebaseData.stringData());
    }else{
      Serial.println(firebaseData.errorReason());
    }
  }
}
// ========================================================================================================

// ========================================================================================================
/**
 * @brief Definir o objeto firebase
 * 
 * @note Descomentar qual tipo de variável você quer usar
 */
void SET_FIREBASE() {
//---exemplo da função Set escreve edita valor, ou pode criar tambem---

//---bool---
  // Firebase.setBool(firebaseData, ID_para_teste_inovacao, false);
  // delay(150);

  // //---para teste---
  // cont++;
  // delay(1000);

  // bool trava = true;
  // do {
  //  if(Firebase.setBool(firebaseData, ID_para_teste_inovacao, false)) {
  //    trava = false;
  //    delay(150);
  //  }else{
  //    Serial.println(firebaseData.errorReason());
  //  }
  // }while(trava == true);

//---int---
  // Firebase.setInt(firebaseData, ID_para_teste_inovacao, cont);
  // delay(150);

  // //---para teste---
  // cont++;
  // delay(1000);

  // bool trava = true;
  // do {
  //  if(Firebase.setInt(firebaseData, ID_para_teste_inovacao, cont)) {
  //    trava = false;
  //    delay(150);
  //  }else{
  //    Serial.println(firebaseData.errorReason());
  //  }
  // }while(trava == true);

//---float---
  // Firebase.setFloat(firebaseData, ID_para_teste_inovacao, 29.4);
  // delay(150);

  // //---para teste---
  // cont++;
  // delay(1000);

  // bool trava = true;
  // do {
  //  if(Firebase.setFloat(firebaseData, ID_para_teste_inovacao, 29.4)) {
  //    trava = false;
  //    delay(150);
  //  }else{
  //    Serial.println(firebaseData.errorReason());
  //  }
  // }while(trava == true);

//---string---
  // Firebase.setString(firebaseData, ID_para_teste_inovacao, "teste_123");
  // delay(150);

//---para teste---
  cont++;
  delay(1000);

  bool trava = true;
  do {
   if(Firebase.setString(firebaseData, ID_para_teste_inovacao, "teste_123")) {
     trava = false;
     delay(150);
   }else{
     Serial.println(firebaseData.errorReason());
   }
  }while(trava == true);
}
// ========================================================================================================

// ========================================================================================================
/**
 * @brief Definir o objeto firebase
 * 
 * @note Descomentar qual tipo de variável você quer usar
 */
void PUSH_FIREBASE() {
//---exemplo da função Push cria nova aba (raiz)---

//---bool---
  // bool sucesso = Firebase.setBool(firebaseData, ID_para_teste_inovacao, true);

//---int---
  // bool sucesso = Firebase.pushInt(firebaseData, ID_para_teste_inovacao, 29);

//---float---
  // bool sucesso = Firebase.pushFloat(firebaseData, ID_para_teste_inovacao, 29.4);

//---string---
  bool sucesso = Firebase.pushString(firebaseData, "ID_para_teste_inovacao", "teste");

  if(sucesso) {
    Serial.println("Envio bem-sucedido!");
  }else{
    Serial.println("Erro ao enviar. Verifique sua conexão ou configuração do Firebase.");
    Serial.println(firebaseData.errorReason());
  }

  delay(1000);
}
// ========================================================================================================

// ========================================================================================================
/**
 * @brief Verificação do WI-FI
 * 
 * @note Verificação do wifi, essa função pose ser usado ou não
 */
void VERIFICACAO_WIFI() {
  //---inicialize a conexão wi-fi---
  wifi_conexao = CONECT_WIFI();

  if(wifi_conexao) {
    Serial.println("");
    Serial.println("Conectado no WiFi");
//---código para colocar se wifi está conectado---
  }else{
    while(1) {
      Serial.println("");
      Serial.println("Não é possível conectar ao Wi-Fi. Verifique os dados e reinicie o ESP.");
      delay(2500);
      //---reset o esp---
      ESP.restart(); 
    }
  } 
}
// ========================================================================================================

// ========================================================================================================
/**
 * @brief Wi-Fi Conexão
 * 
 * @return boolean 
 */
boolean CONECT_WIFI() {
  boolean state = true;
  int cont = 0;

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.println("Conectando-se ao Wi-Fi");

//---aguarde a conexão---
  Serial.print("Conectando...");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if(cont > 20) {
      state = false; 
      break;
    }
    cont++;
  }
  Serial.println("");
  if(state) {
    Serial.print("Conectado a ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    server.begin();
  }else{
    Serial.println("Falha na conexão.");
  }
  return state;
}
// ========================================================================================================

// ========================================================================================================
/**
 * @brief Configure o objeto Firebase
 * 
 */
void SETUP_FIREBASE() {
  //---setup das conexões firebase---
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  //---chamar conexão automática se o wi-fi cair---
  Firebase.reconnectWiFi(true);
}
// ========================================================================================================
