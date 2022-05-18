Philosophers -
<img width="1060" alt="image" src="https://user-images.githubusercontent.com/58044383/168993268-93980649-fcbf-429a-bbf2-52a6a2ef4c22.png">


Флаг
----
для проверки гонки данных
   
    -fsanitize=thread
    
<img width="855" alt="image" src="https://user-images.githubusercontent.com/58044383/168979080-999496e9-1eed-403e-aa4c-7b5a51249930.png">


Тестер:
------
- [socrates](https://github.com/nesvoboda/socrates)
    
1.Клонируем этот репозиторий рядом с каталогом нашего проекта.
```
     git clone https://github.com/nesvoboda/socrates
```     
```     
    |- philosophers/
    |- socrates/
```

2. Запускаем тест
```
   cd socrates
   python3.7 socrates.py  ../philosophers (<путь к папке с философами>)
```
    
3. Если чего то не хватает доинсталируем это
```
    pip3.7 install <то чего не хватает>
```    
<img width="889" alt="image" src="https://user-images.githubusercontent.com/58044383/168987893-01b44b20-565e-49f3-b2ee-84c3c18c0761.png">
<img width="903" alt="image" src="https://user-images.githubusercontent.com/58044383/168987970-33c8a0d9-71ca-42c9-9778-66911f459ba5.png">



Визуазизатор:
------------
- [philosophers visualizer](https://nafuka11.github.io/philosophers-visualizer/)
<img width="1354" alt="image" src="https://user-images.githubusercontent.com/58044383/168973819-a8f17be5-1c02-4c21-ac87-bec3bd460ca3.png">

Чеклист
-------
- [чеклист](https://github.com/mharriso/school21-checklists/blob/master/ng_4_philosophers.pdf)
<img width="976" alt="image" src="https://user-images.githubusercontent.com/58044383/168980375-9d0cb3ab-7399-456d-bf5c-9afb9e579212.png">


Полезные материалы:
-------------------
- Разбор обедающих философов в [лекции](https://www.youtube.com/watch?v=WzsPbwIwtiw&t=1616s) от marmand, еще [лекция](https://www.notion.so/Philosophers-4a4982d5c1aa4e2db3a8cfd2df7bd1cd).
- Цикл лекций по потокам и процессам [Unix Threads in C](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2) от CodeVault.
- У Столярова "Программирование: введение в профессию" [том 2](http://www.stolyarov.info/books/pdf/progintro_dmkv2.pdf) глава 7, страница 516 и "Введение в операционные системы" [лекция 13, страница 162](http://www.stolyarov.info/books/pdf/osintro.pdf)
- Статьи по [дедлоку](https://learnc.info/c/pthreads_deadlock.html), по [потокам](https://habr.com/ru/post/326138/), по [структуре процессов](http://citforum.ru/operating_systems/bach/glava_56.shtml).

P.S.
---
Хорошо сделанные философы живут в случаях:

    21 290 100 100
    50 210 100 100
    199 2000 600 60

на школьных Маках с одновременно работающей конференцией в Зуме.
