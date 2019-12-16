# Veri Yapıları - Ödev

## Problem : 
Bir bağlı listede tekrar eden sayıları bulup çıkarmak.

## Çözüm 1:
Dizide ki aynı elemanları for döngüsü kullanarak çıkarma.

## Çözüm 2 : 
Listenin tüm elemanlarını diğer elemanlar ile karşılaştırıp tekrar eden sayıları çıkarmak.

## Çözüm 3 : 
Listeyi önce sıralayıp sonrasında tekrar eden sayıları çıkarmak. Bu çözüm için Merge Sort kullanıldı. 


## Merge Sort (Birleştirme Sıralaması) :
Verinin hafızada sıralı tutulması için geliştirilmiştir. Basitçe inceleyecek olursak diziyi ikişer elemanlı kalana kadar parçalara iner sürekli olarak ikiye böler.  Sonra bu parçaları kendi içlerinde önce sıralar ve daha sonra birleştirme işlemini gerçekleştirir. Sonuçta elde edilen dizi sıralı dizinin kendisi olur.


## İlk çözüm olarak veri yapısı kullanılmamış iç içe for döngüsü kullanılmıştır. İkinci çözüm olarak linked-list veri yapısı kullanılmıştır. 

## Bağlı liste : 
Herhangi bir tipten node’ların (düğümlerin) yine kendi tiplerinden düğümlere işaret etmesi (point) ile oluşan zincire verilen isimdir.

Dizi de ise eleman ekleme ve eleman silme işlemleri için, eleman eklenen (veya silinen) konumun sağındaki tüm dizi elemanlarının kaydırılması gerekir. Oysa liste yapılarında eleman (düğüm) ekleme ve silme işlemi sadece birkaç bağlantının güncellenmesinden ibarettir. Dizi, bellekte ardışıl konumlarda oluşturulur; fakat dizinin eleman sayısı önceden bilinmeyebilir. Bu durumda dizi
az elemanlı oluşturulursa yetersiz kalabilir; çok elemanlı açılırsa ise bellek israfı söz konusu olabilir. 

