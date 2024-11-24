#include <DFMiniMp3.h> 
class Mp3Notify; 
typedef DFMiniMp3<HardwareSerial, Mp3Notify> DfMp3; 
DfMp3 dfmp3(Serial2); 
class Mp3Notify 
{  public: static void PrintlnSourceAction(DfMp3_PlaySources source, const char* action)    { 
      if (source & DfMp3_PlaySources_Sd)      { 
              Serial.print("SD Card, ");      } 
                    if (source & DfMp3_PlaySources_Usb)      { 
                            Serial.print("USB Disk, ");      } 
                                  if (source & DfMp3_PlaySources_Flash)      { 
                                          Serial.print("Flash, ");      } 
                                                Serial.println(action);    } 
                                                    static void OnError([[maybe_unused]] DfMp3& mp3, uint16_t errorCode)    {       
                                                          Serial.println(); 
                                                                Serial.print("Com Error "); 
                                                                      Serial.println(errorCode);   } 
                                                                          static void OnPlayFinished([[maybe_unused]] DfMp3& mp3, [[maybe_unused]] 
                                                                          DfMp3_PlaySources source, uint16_t track) 
                                                                              {   Serial.print("Play finished for #"); 
                                                                                    Serial.println(track); 
                                                                                                track += 1; if (track > 500) 
                                                                                                      {   track = 1;  }  
                                                                                                      dfmp3.playMp3FolderTrack(80);      } 
                                                                                                          static void OnPlaySourceOnline([[maybe_unused]] DfMp3& mp3, DfMp3_PlaySources 
                                                                                                          source)    { 
                                                                                                                PrintlnSourceAction(source, "online");    } 
                                                                                                                    static void OnPlaySourceInserted([[maybe_unused]] DfMp3& mp3, DfMp3_PlaySources 
                                                                                                                    source)    { 
                                                                                                                          PrintlnSourceAction(source, "inserted"); } 
                                                                                                                              static void OnPlaySourceRemoved([[maybe_unused]] DfMp3& mp3, DfMp3_PlaySources 
                                                                                                                              source) 
                                                                                                                                  {PrintlnSourceAction(source, "removed"); } }; 
                                                                                                                                  const int trigPin = 25; 
                                                                                                                                  const int echoPin = 26; 
                                                                                                                                  long duration; 
                                                                                                                                  int distance; 
                                                                                                                                  void setup() { 
                                                                                                                                     Serial.begin(115200); 
                                                                                                                                       Serial2.begin(9600); 
                                                                                                                                         pinMode(trigPin, OUTPUT); 
                                                                                                                                           pinMode(echoPin, INPUT); 
                                                                                                                                             dfmp3.begin(); 
                                                                                                                                               dfmp3.reset(); 
                                                                                                                                                 uint16_t version = dfmp3.getSoftwareVersion(); 
                                                                                                                                                   Serial.print("version "); 
                                                                                                                                                     Serial.println(version); 
                                                                                                                                                       dfmp3.setVolume(25); 
                                                                                                                                                         uint16_t volume = dfmp3.getVolume(); 
                                                                                                                                                           Serial.print("volume "); 
                                                                                                                                                             Serial.println(volume); 
                                                                                                                                                               uint16_t count = dfmp3.getTotalTrackCount(DfMp3_PlaySource_Sd); 
                                                                                                                                                                 Serial.print("files "); 
                                                                                                                                                                   Serial.println(count); 
                                                                                                                                                                     Serial.println("starting..."); 
                                                                                                                                                                       Serial.println(F("DFPlayer Mini online.")); Serial.println("Put your card to the reader..."); } 
                                                                                                                                                                       void loop() { 
                                                                                                                                                                           digitalWrite(trigPin, LOW); 
                                                                                                                                                                             delayMicroseconds(2); 
                                                                                                                                                                               digitalWrite(trigPin, HIGH); 
                                                                                                                                                                                 delayMicroseconds(10); 
                                                                                                                                                                                   digitalWrite(trigPin, LOW); 
                                                                                                                                                                                       duration = pulseIn(echoPin, HIGH); 
                                                                                                                                                                                          distance = duration * 0.037 / 2;  
                                                                                                                                                                                           if (distance < 15) 
                                                                                                                                                                                            {  delay(3000);   
                                                                                                                                                                                              delay(3000);  
                                                                                                                                                                                                  delay(3000);   } 
                                                                                                                                                                                                   else { 
                                                                                                                                                                                                    delay(1000); 
                                                                                                                                                                                                     Serial.print(distance); 
                                                                                                                                                                                                      Serial.println(" cm"); 
                                                                                                                                                                                                        delay(500); }