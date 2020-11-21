                             SİSTEM PROGRAMLAMA PROJE ÖDEVİ
                                    2020 BAHAR DÖNEMİ
Bu projede siz Dünyadaki güçlü şifa uzmanı Lokman Hekimsiniz. Siz ve arkadaşlarınız Korona Virüsü yenmek için
birlikte çalışacaksınız.

Lokman Hekim olarak işiniz, “Zincir İyileştirme” metotlu ilacınızla insanları güçlü tutmaktır. “Zincir İyileştirme” metodu,
Lokman Hekim'in güç kaybına uğramış bir insanı (bu proje için artık insana oyuncu diyeceğiz) seçmesini ve
iyileştirmesini sağlar. Lokman Hekim gücü bitinceye kadar iyileştirme işlemine zincir halinde devam eder. Bir
oyuncudan belirli bir aralıktaki başka bir oyuncuya geçer ve onları da iyileştirir/güçlendirir. İyileştirmek ne anlama
geliyor? Her oyuncunun hem mevcut enerjisi (pacification point: PP) ve hem de olabilecek maksimum enerji miktarı
belirlidir. Zincir İyileştirme metodu, temas ettiği oyuncular için PP'yi maksimum miktara yükseltmeye çalışır.
Örneğin, Zincir İyileştirme işlemine başlayan Lokman Hekim’in toplamda 300PP’lik dağıtabilecek potansiyel enerjisi
olsun. Bir oyuncunun 100PP enerjisi varsa ve enerjisi maksimum 500PP'ye çıkabiliyorsa; Lokman Hekim bu oyuncuya
dokunduğunda enerjisi 400PP'ye çıkar. Eğer Lokman Hekim bu oyuncuyu tekrar iyileştirecek olsaydı, enerjisi 700PP’ye
değil ancak 500PP’ye çıkacaktı (MAX 500PP olabildiğinden).
Zincir İyileştirme metodunun kısıtları şunlardır:

1) Lokman Hekim bir başlangıç aralığı (initial_range) içinde hedeflere ulaşabilir. Lokman Hekim kendini de hedef
alabilir.
2) Zincir İyileştirme metodunun başlangıç hedefinden sonraki hedeflere ulaşabileceği aralık, sıçrama aralığı
(jump_range) ile sınırlıdır.
3) Zincir İyileştirme sadece belirli miktarda sıçrama (num_jumps) için oyuncuları iyileştirebilir.
4) İlk hedefe yapılacak potansiyel iyileşme miktarı bir başlangıç gücüne (initial_power) eşittir.
5) Sonraki hedeflere yönelik potansiyel iyileşme miktarları, her sıçramada bir güç azalması faktörü ile yeniden
belirlenir.
6) Zincir İyileştirme metodu bir oyuncuyu yalnızca bir kez iyileştirebilir.

Başka bir örneğe bakalım. Lokman Hekimin ilk gücü 500 ve güç azalma katsayısı 0.25 olan bir Zincir İyileştirme işlemi
yapsın. Bu iyileştirme sürecinin aşağıdaki kişilerden verilen sırayla geçeceğini varsayalım:

1) Kara_Murat (100/500PP)
2) Koca_Yusuf (400/450PP)
3) Nasrettin_Hoca (45/400PP)
4) Cengiz_Han (300/600PP)

Lokman Hekim 500PP potansiyel güce sahip olmasına rağmen, iyileşme maksimum PP'nin üzerinde olamayacağı için
Kara Murat’a 400PP’lik güç takviyesi yapacaktır. Sonra Koca Yusuf’a geldiğinde, Lokman Hekimin gücü % 25 azalmış
olacak; yani 500 * (1 - 0.25) = 375 olacak. Koca Yusuf için ise 50PP iyileşme yapılacak, çünkü maksimim güç 450PP
olarak belirlenmiş. Lokman Hekimin gücü şimdi 375 * (1 - 0.25) = 281.25 oldu, yani Nasrettin Hoca için ancak 281PP
güç kaldı (iyileştirme miktarları tamsayı olmalıdır, bu yüzden ondalıklı güç miktarı uygun şekilde yuvarlanmalı, bunun
için ise math.h'den rint() fonksiyonu kullanılmalıdır. rint() fonksiyonu için bağlama (link) aşamasında “-lm” kullanmayı
unutmayın. Son olarak, güç 281.25 * (1 - 0.25) = 210.9375 olur, böylece Cengiz Han ancak 211PP iyileşme/güç kazanır.
Teslim Tarihi: 6 Nisan 2020 Pazartesi Saat:23:59
Teslim şekli: SABİS üzerinden ve grup içinde sadece bir kişi sisteme yükleme yapmalıdır. Kaynak kodlar
(*.c, *.h), Readme ve Makefile dosyaları sıkıştırılmış halde sisteme yüklenmelidir. Yüklenen dosyada asla
yürütülebilir dosya olmamalıdır.

Yapılacak İşler:

Bu proje kapsamında “Zincir İyileştirme” için en uygun yolu bulan chain_heal.c programını yazmanız bekleniyor
(dokunulan oyuncuya en fazla PP yüklenmeli). Program aşağıdaki gibi çalıştırılacaktır:
LINUX> chain_heal initial_range jump_range num_jumps initial_power
power_reduction < input_file
Komut satırındaki parametrelerden sadece power_reduction double tipindedir, diğerleri tamsayıdır. Chain_heal
programı standart girişten (stdin) programdaki oyuncular hakkında bilgi alır. Her satır tek bir oyuncu hakkında bilgi
içerir ve tam olarak 5 kelimeden oluşur:
1) X (Tamsayı): Oyuncunun 2B uzaydaki x koordinatı.
2) Y (Tamsayı): Oyuncunun y koordinatı.
3) Mevcut_PP (Tamsayı): Oyuncunun mevcut iyilik/güç puanı.
4) Max_PP (Tamsayı): Oyuncunun maksimum iyilik/güç puanı.
5) Ad (String, en fazla 100 karakter): Oyuncunun adı.

Oyunculardan biri her zaman Lokman Hekim olacaktır, çünkü o Zincir İyileştirme yapan kişidir. Aşağıda kısa bir giriş
dosyası içeriği örnek olarak verilmiştir:
.....

Giriş verileri için hata kontrolü yapmak zorunda değilsiniz. Daima doğru biçimde olduğunu ve aynı ada sahip iki
oyuncu olmadığını varsayabilirsiniz.

En uygun yolu belirledikten sonra, her satıra bir oyuncu olacak şekilde yolu yazdırmalısınız. Her satırda, güç
kazanan/iyileşen oyuncunun adı, ardından bir boşluk ve yapılan iyileştirme miktarı yazılmalıdır. Buna ek olarak, en
sona "Toplam_İyileşme" kelimesi ve ardından boşluk ve Zincir İyileştirme tarafından yapılan toplam iyileştirme
miktarını içeren son bir satır yazdırmalısınız.
Yukarıdaki örnek giriş için çıktı aşağıdaki gibi olmalıdır:

LINUX> ./chain_heal 2 1 4 500 0.25 < small.txt
Kara_Murat 400
Koca_Yusuf 50
Nasrettin_Hoca 281
Cengiz_Han 211
Toplam_İyileşme 942
