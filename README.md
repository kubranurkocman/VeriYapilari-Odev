# Veri Yapıları - Ödev

## Problem : 
Bir bağlı listede tekrar eden sayıları bulup çıkarmak.

## Çözüm 1 : 
Listenin tüm elemanlarını diğer elemanlar ile karşılaştırıp tekrar eden sayıları çıkarmak. Time Complexity O(n^2)


## Çözüm 2 : 
Listeyi önce sıralayıp sonrasında tekrar eden sayıları çıkarmak. Bu çözüm için Merge Sort kullanıldı. O yüzden Time Complexity O(nlogn)

## Time Complexity :
Time complexity bir algoritmanın çalışması için gerekli olan süredir. Ancak buradaki süre, saniyeleri hesaplayarak değil, kaç tane işlem gerçekleştirdiğine göre hesaplanmaktadır. Uygulama tarafından gerçekleştirilen işlem sayısı, veri setinin büyüklüğüne ve o veri setindeki elemanlarına sırasına göre belirlenir.
## O(n^2) : 
İnput büyüklüğünün karesi ile doğru orantılıdır.Eğer input büyüklüğü 2 ise, 4 işlem gerçekleşir

## Merge Sort (Birleştirme Sıralaması) :
Verinin hafızada sıralı tutulması için geliştirilmiştir. Basitçe inceleyecek olursak diziyi ikişer elemanlı kalana kadar parçalara iner sürekli olarak ikiye böler.  Sonra bu parçaları kendi içlerinde önce sıralar ve daha sonra birleştirme işlemini gerçekleştirir. Sonuçta elde edilen dizi sıralı dizinin kendisi olur.






