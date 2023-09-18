.. _connect_blynk:

1.4 R3ボードをBlynkに接続
---------------------------------

#. ESP8266モジュールとR3ボードを再接続します。ここではソフトウェアシリアルが使用されているため、TXとRXはR3ボードのピン2と3にそれぞれ接続されます。

    .. note::

        ESP8266モジュールは、安定した動作環境を提供するために高い電流を必要とします。9Vのバッテリーが接続されていることを確認してください。

    .. image:: img/wiring_23.jpg

#. ``3in1-kit\iot_project\1.connect`` のパスの下の ``1.connect.ino`` ファイルを開きます。または、このコードを **Arduino IDE** にコピーします。

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/1c0c1a8f-2551-484f-9f4f-d5d4117cc864/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. **Device info** ページからコピーできる以下の3行のコードを置き換えます。これらの3行のコードにより、R3ボードがあなたのblynkアカウントを見つけることができます。

    .. code-block:: arduino

        #define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
        #define BLYNK_DEVICE_NAME "Device"
        #define BLYNK_AUTH_TOKEN "YourAuthToken"
    
    .. image:: img/sp20220614174721.png

#. 使用しているWiFiの ``ssid`` と ``password`` を入力します。

    .. code-block:: arduino

        char ssid[] = "ssid";
        char pass[] = "password";

#. コードをR3ボードにアップロードします。次に、シリアルモニタを開き、ボーレートを115200に設定します。R3ボードがBlynkと正常に通信すると、シリアルモニタに ``ready`` 文字が表示されます。

    .. image:: img/sp220607_170223.png

    .. note::
    
        接続するときに ``ESP is not responding`` というメッセージが表示された場合、以下の手順に従ってください。

        * 9Vのバッテリーが接続されていることを確認してください。
        * RSTピンを1秒間GNDに接続してESP8266モジュールをリセットし、それを抜きます。
        * R3ボードのリセットボタンを押します。

        これらの操作を3〜5回繰り返す必要がある場合があります。お手数をおかけしますが、お待ちください。

#. Blynkのステータスが **offline** から **online** に変わります。

    .. image:: img/sp220607_170326.png
