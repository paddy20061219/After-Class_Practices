# LeetCode 763 - Partition Labels

## 題目重點

這題會給一個字串 `s`。

題目要把字串切成好幾段，而且要符合一個規則：

```txt
同一個字母只能出現在同一段裡面
```

也就是說，如果字母 `a` 出現在第一段，  
那所有的 `a` 都必須在第一段，不能跑到第二段。

題目要回傳每一段的長度。

例如：

```txt
s = "ababcbacadefegdehijhklij"
```

答案是：

```txt
[9,7,8]
```

切法大概是：

```txt
ababcbaca
defegde
hijhklij
```

每個字母都只會出現在自己的那一段裡。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// LeetCode 763 - Partition Labels
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;

        // 蠢錯誤：直接把整個字串當成一段
        // 題目要切成盡量多段，不是全部包在一起。
        ans.push_back(s.length());

        return ans;
    }
};
```

---

## 錯誤原因

這個錯誤版本直接把整個字串長度放進答案。

也就是它永遠只切成一段。

例如：

```txt
s = "ababcbacadefegdehijhklij"
```

錯誤程式碼會回傳：

```txt
[24]
```

可是題目希望切成盡量多段，而且每段都要符合規則。

正確答案應該是：

```txt
[9,7,8]
```

雖然把整個字串當成一段，有時候規則上不一定會錯，  
但題目要的是可以切成越多段越好。

所以不能直接全部包成一段，要真的判斷每個字母最後出現在哪裡。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// LeetCode 763 - Partition Labels
// AC version

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, 0);

        // 先記錄每個字母最後一次出現的位置
        for(int i = 0; i < s.length(); i++){
            last[s[i] - 'a'] = i;
        }

        vector<int> ans;

        int start = 0;
        int end = 0;

        for(int i = 0; i < s.length(); i++){
            end = max(end, last[s[i] - 'a']);

            // 如果 i 走到目前這段的最右邊
            // 代表這一段可以切開
            if(i == end){
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};
```

---

## 解題想法

這題的重點是：

```txt
如果某個字母還會在後面出現，那現在這一段就不能結束
```

所以第一步要先記錄每個字母最後一次出現的位置。

例如：

```cpp
last[s[i] - 'a'] = i;
```

這樣之後看到某個字母時，就知道這個字母最晚要包到哪裡。

接著用兩個變數：

```cpp
start = 目前這段的開始位置
end = 目前這段最遠一定要包到的位置
```

從左到右掃字串。

每看到一個字母，就更新這段的最遠位置：

```cpp
end = max(end, last[s[i] - 'a']);
```

意思是：

```txt
目前這段至少要包到這個字母最後出現的位置
```

如果走到某個位置時：

```cpp
i == end
```

代表目前這段裡面所有字母都已經結束了，  
後面不會再出現這段的字母。

所以可以切一段：

```cpp
ans.push_back(end - start + 1);
start = i + 1;
```

---

## 心得

這題一開始看起來像字串題，但其實有一點 greedy 的想法。

不能看到不同字母就馬上切，  
因為前面的字母可能後面還會再出現。

我覺得這題最重要的是先找出每個字母的最後位置。  
知道最後位置後，才知道現在這段最少要延伸到哪裡。

這題比普通字串掃描難一點，但用 `start` 和 `end` 想會比較清楚。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
