# Polynom - полиномы с рациональнымии коэффициентами

## Следующие функции включены в `../modules/polynom/polynom.h`

### ADD_PP_P.cpp

```c++
polynom ADD_PP_P(const polynom& left, const polynom& right);
```
Принимает два полинома. Возвращает их сумму, полином.

### COM_PP_D.cpp

```c++
ordinal COM_PP_D(const polynom& left, const polynom& right);
```
Принимает два полинома. Возвращает результат их сравнения. Результаты сравнения определены в `../structs/ordinal.h`
```c++
ordinal::LT;  // Меньше
ordinal::EQ;  // Равно
ordinal::GT;  // Больше
```
Оператор соответствия для полиномов определён в этом файле.
```c++
bool operator == (const polynom& left, const polynom& right);
```

### DEG_P_N.cpp

```c++
natural DEG_P_N(const polynom &pn);
```
Принимает полином. Возвращает его степень, натуральное число.

### DER_P_P.cpp

```c++
polynom DER_P_P(const polynom& polynom_1);
```
Принимает полином. Возвращает его производную, полином.

### DIV_PP_P.cpp

```c++
polynom DIV_PP_P(const polynom& left, const polynom& right);
```
Принимает два полинома. Возвращает неполное частное от деления первого на второй, полином.

### FAC_P_PQ.cpp

```c++
polynom FAC_P_PQ(polynom polinom);
```
Принимает полином. Возвращает полином полученный из него вынесением НОК знаменателей коэффициентов и НОД числителей.

### GCF_PP_P.cpp

```c++
GCF_PP_P(const polynom& left, const polynom& right);
```
Принимает два полинома. Возвращает их НОД, полином.

### LED_P_Q.cpp

```c++
fraction LED_P_Q(const polynom& input);
```
Принимает полином. Возвращает его старший коэффициент, рациональное число.

### MOD_PP_P.cpp

```c++
polynom MOD_PP_P(const polynom& delimoe, const polynom& delitel);
```
Принимает два полинома. Возвращает остаток от деления первого на второй, полином.

### MUL_PP_P.cpp

```c++
polynom MUL_PP_P(const polynom& left, const polynom& right);
```
Принимает два полинома. Возвращает их произведение, полином.

### MUL_PQ_P.cpp

```c++
polynom MUL_PQ_P(const polynom &pn, const fraction &num2);
```
Принимает полином и рациональное число. Возвращает их произведение, полином.

### MUL_Pxk_P.cpp

```c++
polynom MUL_Pxk_P(const polynom &value, const unsigned &power);
```
Принимает полином и положительное целое (`int`). Возвращает полином умноженный на x в степени целого.

### SUB_PP_P.cpp

```c++
polynom SUB_PP_P(polynom left, polynom right);
```
Принимает два полинома. Возвращает результат вычитания второго из первого, полином.