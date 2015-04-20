# struct.h
### Описание структур и объявленных методов

#### digit - наши цифры
{ _1, _2, _3, _4, _5, _6, _7, _8, _9 }
Именно так можно записывать числа.
Выше записано число "123456789".

##### Инкримент цифры
```c++
inc(digit &a, bool &overflowFlag)
```
Принимает цифру `digit &a` и флаг переполнения `bool &overflowFlag`
Значение флага `true`, если на предыдущем разряде не было переполнения (результат применения чего-то к нему меньше десяти), и `false`, если было.
Флаг переполнения необходимо передавать в качестве переменной, чтобы использовать в следующих разрядах.
Поскольку цифра и флаг передаются по ссылке, после применения функции они изменяются.
* Примеры вызова
```c++
bool overflowFlag = false;
digit a = _8;
inc(a, overflowFlag);  // a == _9; overflowFlag == false
inc(a, overflowFlag);  // a == _0; overflowFlag == true
a = _8;
overflowFlag = true;
inc(a, overflowFlag);  // a++ + 1; a == _0; overflowFlag == true
```
##### Сложение цифр
```c++
digit add(const digit &a, const digit &b, bool &overflowFlag)
```
Принимает цифры `const digit &a` и `const digit &b` и уже знакомый флаг переполнения. Возврощает результат сложения цифрой. Модифицирует флаг переполнения.
* Примеры вызова
```c++
digit result;
bool overflowFlag = false;
result = add(_4, _2, overflowFlag);  // result == _6; overflowFlag == false
result = add(_4, result, overflowFlag);  // result == _0; overflowFlag == true
overflowFlag = true;
result = add(_9, _0, overflowFlag);  // 9 + 0 + 1; result == _0; overflowFlag == true;
```

### natural - натуральные числа
Включают:
`std::vector<digit> digits;` - вектор цифр. От массива при использовании отличается не сильно. Краткое описание можно найти в файле `vector.md`
**Важный момент:** цифры хранятся от младшего разряда к старшему. Таким образом число 9426 в векторе хранится как [ 6, 2, 4, 9 ], т.е. digits[0] ==  и т.д.
#### Инициализация чисел
```c++
natural a();  // a == 0 <=> a.digits[0] == _0
natural a(b)  // a == b
natural a = {_9, _4, _2, _6}  // a == 9426
```
#### Определение порядка (на данный момент забагованно)
```c++
a = {_9, _4, _2, _6}  // a == 9426
a.order()  // Должно вернуть 4
```
