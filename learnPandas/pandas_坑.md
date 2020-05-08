import pandas as pd
import numpy as np

df = pd.DataFrame({'col':[1,2,'3']})
df.dtypes # object

def test(df):
    df['col'].replace({'3': 2}, inplace=True)

test(df)
df.dtypes # 自动变成\int64！坑！
