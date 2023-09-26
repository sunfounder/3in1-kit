.. _connect_blynk:

1.4 R4ボードをBlynkに接続する
--------------------------------------------

#. ESP8266モジュールとR4ボードを再接続します。ここではソフトウェアシリアルを使用しているため、TXとRXはそれぞれR4ボードの2番ピンと3番ピンに接続されます。

    .. note::

        ESP8266モジュールは安定した動作環境を提供するために高電流が必要ですので、9Vの電池が接続されていることを確認してください。

    .. image:: img/iot_1.4_bb.png

#. ``3in1-kit\iot_project\1.connect`` のパスの下にある ``1.connect.ino`` ファイルを開くか、このコードを **Arduino IDE** にコピーします。

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/1c0c1a8f-2551-484f-9f4f-d5d4117cc864/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. あなたのアカウントの **Device info** ページからコピーできる以下の3行のコードを置き換えます。これら3行のコードにより、R4ボードがあなたのblynkアカウントを見つけることができます。

    .. code-block:: arduino

        #define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
        #define BLYNK_DEVICE_NAME "Device"
        #define BLYNK_AUTH_TOKEN "YourAuthToken"
    
    .. image:: img/sp20220614174721.png

#. 使用中のWiFiの ``ssid`` および ``password`` を入力します。

    .. code-block:: arduino

        char ssid[] = "ssid";
        char pass[] = "password";

#. コードをR4ボードにアップロードし、シリアルモニタを開いてボーレートを115200に設定します。R4ボードがBlynkと正常に通信すると、シリアルモニタに ``ready`` 文字が表示されます。

    .. image:: img/sp220607_170223.png

    .. note::
    
        接続時に ``ESP is not responding`` というメッセージが表示される場合は、以下の手順に従ってください。

        * 9Vの電池が接続されていることを確認します。
        * ESP8266モジュールのRSTピンを1秒間GNDに接続してリセットし、その後、それを取り外します。
        * R4ボードのリセットボタンを押します。

        これらの操作を3-5回繰り返す必要がある場合があります。ご了承ください。

#. Blynkのステータスが **offline** から **online** に変わります。

    .. image:: img/sp220607_170326.png
