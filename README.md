# LINE_notify
ArduinoからLINEメッセージを送信します。

# 利用方法  
1.https://notify-bot.line.me/ja/ でLineのトークンを発行します。  
2.config.h.sampleをconfig.hに編集し、SSID, wifipassword, line tokenを記述します。  
3.ESP32に書き込むと、60秒に一回LINE通知が来ます。  
