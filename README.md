
# Türkçe-İngilizce Sözlük/Egzersiz
İngilizce çalışırken bilmediğim ifade/kelimeleri tekrarlayarak ögrenmek için yazdığım ufak bir terminal uygulaması.

## Kurulum
-----------------------------
#### İsterler
- C++11
- Cmake

```
git clone https://github.com/Grafit-Kil/tr_eng
mkdir build
cd build
cmake .. .
make
./main
```

## Kılavuz
Bir metin dosyasına calisma istediginiz kelimeleri şu şekilde girebilirsiniz.

``
reflect=aksettirmek,yansitmak,aksetmek,ifade etmek,gostermek,dusunup tasinmak
``

İlk belirteç İngilizce kelimeyi; ikinci belirteç anlamlarını ayrıştırmak için.

```cpp
Dictionary test("dictionary/dict", '=', ',');
```

Eğer ilk kelimeyi '=' ile ayırmak istemezseniz yahut elinizdeki dosya farklı bir ifade ile ayrılmışsa eşleşme belirtecini değitirebilirisiz.

``
reflect,aksettirmek,yansitmak,aksetmek,ifade etmek,gostermek,dusunup tasınmak
``

```cpp
Dictionary test("dictionary/dict", ',', ',');
```

Hazırladığınız dosyayı dictionary/dict olarak kaydedebilirsiniz eğer dosya yolunu degistirmek siterseniz:


```cpp
Dictionary test("dosya_yolu/dosya_adi", ',', ',');
```

#### Not:
Türkçe karakter destegi yok.
