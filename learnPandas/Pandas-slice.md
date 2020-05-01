
[toc]

切片返回的不是 DataFrame 的值。要用 .loc 来修改

```
output[mask]['Sales'] = 0
/Users/ed/Git/kaggle/rossmann-store-sales/xgboost-with-rmsp.py:1: SettingWithCopyWarning: 
A value is trying to be set on a copy of a slice from a DataFrame.
Try using .loc[row_indexer,col_indexer] = value instead
```

```
output.loc[mask, 'Sales'] = 0
```




