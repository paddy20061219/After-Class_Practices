# LeetCode 860 - Lemonade Change

## 題目重點

這題是在模擬賣檸檬水找錢。

每杯檸檬水固定是：

```txt
5 元
```

每個客人會依序拿一張鈔票來買，鈔票可能是：

```txt
5, 10, 20
```

我們一開始手上沒有任何零錢。

題目要問：

```txt
能不能照順序成功找錢給每一個客人
```

如果每個客人都可以成功找錢，就回傳：

```txt
true
```

只要有一個客人不能找錢，就回傳：

```txt
false
```

例如：

```txt
bills = [5,5,5,10,20]
```

過程：

```txt
客人拿 5，不用找錢，收一張 5
客人拿 5，不用找錢，收一張 5
客人拿 5，不用找錢，收一張 5
客人拿 10，要找 5
客人拿 20，要找 15，可以找 10 + 5
```

所以答案是：

```txt
true
```

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 860 - Lemonade Change
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // 蠢錯誤：直接說一定可以找錢
        // 但如果一開始客人拿 10 或 20，就可能根本沒錢找。
        return true;
    }
};
```

---

## 錯誤原因

這個錯誤版本直接回傳：

```cpp
true
```

意思是它覺得所有情況都可以找錢。

可是題目不一定可以。

例如：

```txt
bills = [10]
```

第一個客人就拿 10 元。

檸檬水只要 5 元，所以要找他：

```txt
5 元
```

但是一開始手上沒有任何 5 元，所以根本不能找錢。

正確答案應該是：

```txt
false
```

但錯誤程式碼會回傳：

```txt
true
```

所以很明顯錯了。

這題一定要記錄手上有幾張 5 元和 10 元，不能直接亂回傳。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 860 - Lemonade Change
// AC version

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5){
                five++;
            } else if(bills[i] == 10){
                if(five == 0){
                    return false;
                }

                five--;
                ten++;
            } else {
                // bills[i] == 20，要找 15 元

                if(ten > 0 && five > 0){
                    ten--;
                    five--;
                } else if(five >= 3){
                    five -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
```

---

## 解題想法

這題只需要記錄兩種零錢：

```txt
5 元有幾張
10 元有幾張
```

因為 20 元不用拿來找錢，題目裡不會需要找超過 15 元。

所以設：

```cpp
int five = 0;
int ten = 0;
```

接著照順序處理每一個客人。

如果客人拿 5 元：

```txt
不用找錢，直接收下
```

所以：

```cpp
five++;
```

如果客人拿 10 元：

```txt
要找 5 元
```

所以一定要有一張 5 元：

```cpp
if(five == 0) return false;
```

如果可以找錢，就：

```cpp
five--;
ten++;
```

如果客人拿 20 元：

```txt
要找 15 元
```

找 15 元有兩種方法：

```txt
10 + 5
5 + 5 + 5
```

通常先用 `10 + 5` 比較好，因為 5 元比較常需要留著找 10 元。

所以先判斷：

```cpp
if(ten > 0 && five > 0)
```

如果不行，再看有沒有三張 5 元：

```cpp
else if(five >= 3)
```

兩種都不行，就回傳 `false`。

---

## 心得

這題是很基本的 greedy 題。

重點是要照客人順序處理，不能排序，因為現實中客人是一個一個來的。  
如果前面沒有零錢，後面就算會收到 5 元也來不及。

我覺得這題最容易忘記的是客人拿 20 元時，  
要先用 `10 + 5` 找錢，這樣比較能保留 5 元。

整體來說，只要記得 `five` 和 `ten` 兩個變數，這題就會比較好寫。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
