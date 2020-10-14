[toc]

### Sorting and Ranking

```
series = pd.Series(range(4), index = list('dcba')) ; series
series.sort_index()
series.sort_values()

series = pd.Series([4, np.nan, 7, np.nan, -3, 2]) ; series
series.sort_values() # NaN will be placed at the end of the each row or each column
series.rank() # NaN in the series will be overlooked

series[series.isnull()] = 1 ; series
series.rank() # Breaking ties by assigning each group the mean rank by default
```


```
frame = pd.DataFrame(np.random.randn(4,4),
                     index = ['three', 'one', 'four', 'two'],
                     columns = list('dabc'))
frame
frame.sort_index()
frame.sort_index(axis = 1, ascending = False)  # ascengding = True by default

# sort by column values
frame.sort_values(by='b')
frame.sort_values(by = ['a', 'b'])

# sort by row values
frame.sort_values(by=['three', 'four'], axis = 1)
frame.rank() # Compute ranks over the columns
frame.rank(axis = 1) # Compute ranks over the rows
```

