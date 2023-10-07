スケッチの作成、開く、保存方法は？
=======================================

#. Arduino IDEを初めて開くか、新しいスケッチを作成すると、このようなページが表示されます。Arduino IDEが新しいファイルを作成してくれます。これを"スケッチ"と言います。

    .. image:: img/sp221014_173458.png

    これらのスケッチファイルは一時的な名前が付けられており、ファイルの作成日から名前を判断することができます。 ``sketch_oct14a.ino`` は10月14日の最初のスケッチを意味し、 ``.ino`` はこのスケッチのファイル形式です。

#. 新しいスケッチを作成してみましょう。以下のコードをArduino IDEにコピーして、元のコードを置き換えます。

        .. image:: img/create1.png

    .. code-block:: C

        void setup() {
            // 初回のセットアップコードをここに記述:
            pinMode(13,OUTPUT); 
        }

        void loop() {
            // 主要なコードをこちらに記述し、繰り返し実行:
            digitalWrite(13,HIGH);
            delay(500);
            digitalWrite(13,LOW);
            delay(500);
        }

#. ``Ctrl+S`` を押すか、 **ファイル（File）** -> **保存（Save）** をクリックします。デフォルトでスケッチは ``C:\Users\{your_user}\Documents\Arduino`` に保存されます。名前を変更したり、新しいパスを指定して保存することもできます。

    .. image:: img/create2.png

#. 保存が成功すると、Arduino IDEの名前が更新されることがわかります。

    .. image:: img/create3.png

次のセクションで、この作成したスケッチをArduinoボードにアップロードする方法を学習してください。