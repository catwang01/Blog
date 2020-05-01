Chapter 6. Data Loading, Storage, and File Formats
6.1 Reading and Writing Data in Text Format
Writing Data to Text Format

Chapter 7. Data Cleaning and Preparation
7.1 Handling Missing Data
Filtering Out Missing Data
Filling in Missing Data

7.2 Data Transformation
Removing Duplicates
Transforming Data Using a Function or Mapping
Replacing Value
Renaming Axis Indexes
Discretization and Binning
Detecting and Filtering Outliers
Permutation and Random Sampling
Computing Indicator/Dummy Variables

7.3 String Manipulation
String Object Methods
Vectorized String Functions in pandas

Chapter 8. Data Wrangling: Join, Combine, and Reshape

8.1 Hierarchical Indexing
Reordering and Sorting Levels
Summary Statistics by Level
Indexing with a DataFrame's columns

8.2 Combining and Merging Datasets
Database-Style DataFrame Joins
Concatenating Along an Axis
Combining Data with Overlap

8.3 Reshaping and Pivoting
Reshaping with Hierarchical Indexing
Pivoting "Long" to "Wide" Format
Pivoting "Wide" to "Long" Format

Chapter 9. Plotting and Visualization

9.1 A Brief matplotlib API Primer
Figures and Subplots
Colors, Markers and Line Styles
Ticks, Labels, and Legends
Annotations and Drawing on a Subplot
Saving Plots of File

9.2 Plotting with pandas and seaborn
Line Plots
Bar Plots
Histograms and Density Plots
Scatter or Point Plots
Facet Grids and Categorical Data

Chapter 10. Data Aggregation and Grop Operation
10.1 Groupby Mechanics
Iteration Over Groups
Selecting a Column of Subset of Columns
Grouping with Dicts and Series
Grouping with Functions
Grouping  by Index Levels

10.2. Data Aggregation
Column-Wise and Multiple Function Application
Returning Aggregated Data Without Row Indexes

10.3 Apply: General split-apply-combine
Suppressing the Group Keys
Quantile and Bucket Analysis
Example: Random Sampling and Pernutation

10.4 Pivot Tabels and cross-Tabulation
cross-Tabulations: Crosstab

Chapter 12. Advanced pandas
12.1 Categorical Data
Background and Motivation
Categorical Type in pandas
Computations with Categoricals
Categorical Method

12.2 Advanced GroupBy Use
Group Transforms and "Unwrapped" GroupBys
Grouped Time Resampling

12.3 Techniques for Method Chaining
The pipe Method
'''

import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
import  pandas as pd
import re
# make the pandas display settings more compact
pd.options.display.max_rows = 8

from matplotlib import style
style.available
style.use('ggplot')


#### create a series object

s1 = pd.Series(25, index = ['a', 'b', 'c']) ; s1
s2 = pd.Series({'a':9,'b':8,'c':7}) ; s2
s3 = pd.Series({'a':9,'b':8,'c':7},index = ['c', 'a', 'b', 'd']) ; s3
# NaN means not a number
pd.isnull(s3) # s3.isnull() will work the same
pd.notnull(s3) # s3.notnull() will work the same

s4 = pd.Series(np.arange(5)) ; s4  # automatic index
s5 = pd.Series(np.arange(5), np.arange(5,10)) ; s5 # customized index

b = pd.Series([9, 8, 7, 6], index = ['a', 'b', 'c', 'd'])
b.values
b.index

b['b']
b[1]
b[:3]
b[b > np.median(b])
np.exp(b)
('c' in b) == ('c' in b.index)
0 in b # doesn't work for automatic index

# Series' feature for many applications is that it aligns automatically by index label in arithmetic operations
a = pd.Series(range(1,4), ['c', 'd', 'e']) ; a
b = pd.Series((5,6,7,8,9), ['a', 'b', 'c', 'd', 'e']) ; b
print('a+b:',a+b)


### DataFrame object
d1 = pd.DataFrame(np.arange(10).reshape(2,5)) ; d1
dt = {'one': pd.Series([1,2,3], index = ['a', 'b', 'c']),
      'two': pd.Series([4,5,6,7], index = ['b','c', 'd', 'e'])}
d2 = pd.DataFrame(dt) ; d2


dd = {'one': [1, 2, 3, 4],
    'two': [9, 8, 7, 6]}
d3 = pd.DataFrame(dd, index = ['a', 'b', 'c', 'd']) ; d3

dd = {
    'one': {'a':1, 'b':2, 'c':3, 'd':4},
    'two': {'a':9, 'b':8, 'c':7, 'd':6}
    }
d4 = pd.DataFrame(dd) ; d4  # outer keys will be interpreted as the columns, while inner keys will be the row indices
d4.values
d4.index
d4.columns

### get the elements from dataframe

```
# retrieve columns of the datafram
d4['one'] # retrieve the column by dict-like notation
d4.one # retrieve the column by attribute
# retrieve rows of the dataframe
d4.loc['a']
d4.ix['a'] # DataFrame.ix is similar to DataFrame.loc, however it led to many edge cases in practice, so it is deprecated and not be recommended to use.
# retrieve items of the dataframe
# note that column tag is in front of row tag, different from R
d4['one']['a']

# Assigning a column that doesn't exist will create a new column.
d4
d4['three'] = d4.one == 1 ; d4
d4.four = d4.one == 1 ; d4 # Wrong d4.four syntax cannot create a new  column.
del d4['three'] ; d4 # Right delete a column
del d4.three # Wrong d4.three syntax cannnot delete a column
```

###### 5.2 Essential Functionality

### Reindexing
# DataFrame.reindex(index = None, columns = None, fill_value, method, limit, copy)
# method : 'ffill' fills forward; 'bfill' fills backward
d1 = pd.Series(['blue', 'purple', 'yellow'], index = [1,2,4]) ; d1
d1.reindex([1,2]) # reindex can be used to select columns or indexes
d1.reindex([2,0,1]) # reindex can be used to reorder the rows or columns

d1.reindex(range(6), method = 'ffill') # fill NaN values with the value before it
d1.reindex(range(6), method = 'bfill') # fill NaN values with the value after it

data = {
    'a':[1,2,3],
    'b':[3,4,5],
    'c':[5,6,7]
    }
d2 = pd.DataFrame(data) ; d2
newcolumns = d2.columns.insert(3,'e') ; newcolumns
d2.reindex(columns = newcolumns, fill_value = 300)
d2.reindex(index = [2,3,0,1])
d2
d2.loc[[2, 0, 1], ['b', 'c', 'a']] # reindex more succinctly(简洁，简明) by DataFrame.loc[index, column]
d2.reindex(index = [0,1], columns = ['b', 'a'])

### some methods about the Index object

'''
.append(index)
.diff(index)
.intersection(index)
.union(index)
.delete(location)
.insert(location,value)
.drop() delete columns or rows. axis is 0 by default
'''

### dropping entries from an axis
s = pd.Series(np.arange(5), index = ['a','b','c','d','e']) ; s

new_s = s.drop('c') ; new_s # returns a new without changing the original Series
s.drop(['a', 'b'])

data = pd.DataFrame(np.arange(16).reshape((4,4)),
                    index = ['Ohio', 'Colorado', 'Utah', 'New York'],
                    columns = ['one', 'two', 'three', 'four'])
data

data.drop(['Ohio', 'Utah'])
data.drop(['one', 'four'], axis = 1)
data

new_data = data.drop(['one', 'four'], axis = 1, inplace = True) # inplace means manipulate an object without returning a new object
new_data
data

### Indexing, Selection, and Filtering
s = pd.Series(np.arange(4), index = ['a', 'b', 'c', 'd']) ; s
s['b']
s[1]
s[2:4]
s[['b', 'a', 'c']]
s[[1,3]]
s[s<2]
s['a':'c'] # interesting way to index

data = pd.DataFrame(np.arange(16).reshape(4,4),
                    index = ['Ohio', 'Colorado', 'Utah', 'New York'],
                    columns = ['one', 'two', 'three', 'four'])
data

# indexing columns
data['two'] # Returns a Series
type(data['two'])
data[['two']] # Returns a DataFrame
type(data[['two']])
data[['three', 'two']]
data.two # Returns a Series
data[:,:2] # Wrong

# indexing rows
## how to get the first row of the DataFrame?
data[0:1] # Right
data[0] # Wrong

data[:2] # get row 0,1
data[data['three']>5]
data[data < 5]

# Selection with loc and iloc
data = pd.DataFrame(np.arange(16).reshape(4,4),
                    index = ['Ohio', 'Colorado', 'Utah', 'New York'],
                    columns = ['one', 'two', 'three', 'four'])
data
data.loc['Colorado', ['two', 'three']]
data.loc[:'Utah', 'two']
# DataFrame.loc doesn't accept integer or integer slices as arugments or will yield an error
data.loc[1,[1,2]] # Wrong
data.loc[2] # Wrong

data.iloc[1,[1,2]] # row 1 and columns 1,2
data.iloc[2] # row 2
data.iloc[:,2] # column 2
data.iloc[[1,2],[3,0,1]]

### More about Integer Indexes
s= pd.Series(np.array(['John', 'Mike','Edward'])) ; s
s[-1] # want to get the last item in the series but get an error instead. Maybe a bug

s= pd.Series(np.array(['John', 'Mike','Edward']),index = ['a','b','c']) ; s
s[-1] # change index into non-integer


### Arithmetic and Data Alignment

# the value with same tags will be added and fill the NaNs for columns and rows with no corresponding columns or rows in the other dataframe.
s1 = pd.Series(np.arange(5), index = ['a', 'b', 'c', 'd', 'e']) ; s1
s2 = pd.Series(np.arange(5), index = ['b', 'c', 'd', 'e', 'f']) ; s2
s1 + s2


df1 = pd.DataFrame(np.arange(20).reshape(4,5),
                   index = list(range(4)),
                   columns = list('bcedf'))
df2 = pd.DataFrame(np.arange(20).reshape(5,4),
                   index = list(range(1,6)),
                   columns = list('abcd'))
df1
df2
df1 + df2
# the dataframe.add() can also get the same result with + and it can
df1.add(df2, fill_value = 100)
# others arithmetic methods : .add, .sub, .div, .floordiv, .mul, .pow

### Operations between DataFrame and Series
arr = np.arange(12).reshape(3, 4) ; arr
arr[0]
arr - arr[0] # the subtraction will be performed once for each row.
# Operations between DataFrmae and a Series are similar:
frame = pd.DataFrame(np.arange(12).reshape(4, 3),
                     index = ['Utath', 'Ohio', 'leaxs', 'Oregon'],
                     columns = list('bde'))
frame
series1 = frame.iloc[0]
series1 # the row 0 of the frame
# By default, arithmetic between DataFrame adn Series mathces the index of the Series on the DataFrame's columns, broadcasting down the rows
frame - series1
# if an index vlaue is not found in either the DataFrame's columns or the Series's index, the objects will be reindexed to for the union:
series2 = pd.Series(range(3), index = list('bef')) ; series2
frame - series2
# it actually do like this
newindex = frame.columns.union(series2.index) # get the union index
frame.reindex(columns = newindex) - series2.reindex(newindex) # do the operation after broadcasting with the union index
# If you want to instead broadcast over the columns, matching on the rows, you have to use one of the arithmetic methods.
# the axis number you pass is the axis to match on
series3 = frame.d ; series3
frame - series3
frame.subtract(series3, axis = 0)


# Function Application and Mapping
# NumPy ufuncs(element-wise array methods) also work with pandas objects
frame = pd.DataFrame(np.random.randn(4,3),
                     columns = list('abc'))
frame
np.abs(frame)

# Applying a function on one-dimensional arrays to each column or row
# This is different from the apply function in R, because R's apply function will be invoked on each row by default while pandas's DataFrame's method on each columns.
frame
f = lambda x : x.max() - x.min()
frame.apply(f, axis = 'index') # The function is invoked once on each column when axis = 'index' (by deffault)
frame.apply(f, axis = 'columns') # The function is invoked once on each row when axis = 'columns'.

# The function passed can return a Series
def f(x):
    return pd.Series([x.min(), x.max()],
                     index = ['min', 'max'])
frame.apply(f)
# Element-wise functions can alse be used.
format = lambda x: '%.2f' % x # format is an element-wise function.
frame.applymap(format)
# The reasion for the name applymap is that Series has a map method for applying an element-wise function
frame.a.map(format)
# what .applymap does is as follows
frame.apply(lambda x: x.map(format)) == frame.applymap(format)


### Sorting and Ranking

series = pd.Series(range(4), index = list('dcba')) ; series
series.sort_index()
series.sort_values()

series = pd.Series([4, np.nan, 7, np.nan, -3, 2]) ; series
series.sort_values() # NaN will be placed at the end of the each row or each column
series.rank() # NaN in the series will be overlooked

series[series.isnull()] = 1 ; series
series.rank() # Breaking ties by assigning each group the mean rank by default


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

# Axis Indexes with Duplicate Labels
series = pd.Series(range(5), index = list('aabbc')) ; series
series.index.is_unique # the whether the labels of index are unique or not
series['a']


### 5.3 Summarizing and Computing Descriptive Statistics

# DataFrame.head() / DataFrame.tail()
# DataFrame.sum()
# DataFrmae.prod() : product of all values
# DataFrame.count() : returns the number of non-NaN values
# DataFrame.quantile()
# DataFrame.mean()
# DataFrame.median()
# DataFrame.mad() : Mean absolute deviation
# DataFrame.var() : Sample variance (second moment)
# DataFrame.std()
# DataFrame.skew : Sample skewness (third moment)
# DataFrame.kurt : Sample kurosis (fourth moment)
# DataFrame.min()/max()
# df.cumsu()
# DataFrame.describe() : show the summary information of the dataframe object

df = pd.DataFrame([[1.4, np.nan], [7.1, -4.5],
                   [np.nan, np.nan], [0.75, -1.3]],
                   index = list('abca'), columns = ['one', 'two'])
df
df.sum() # sum the non-NaN values over the rows
df.sum(axis = 1) # sum the non-NaN values over the columns
df.prod()
df.mean(axis = 1, skipna = False)
df.mad(axis = 1)
df.cumsum()
df.describe()
df.mean(axis = 1, level = )

### Unique Values, Value Counts, and Membership

```
series = pd.Series(list('cadaabbcc')) ; series
uniques = series.unique() ; uniques # Similar to function unique() in R
series.value_counts() # Similar to function table() in R computing a Series containing value frequencies

mask = series.isin(list('bc')) ; mask
series[mask]
```
# demo
data = pd.DataFrame({'Qu1':[1, 3, 4, 3, 4],
                     'Qu2':[2, 3, 1, 2, 3],
                     'Qu3':[1, 5, 2, 4, 4]}
                    )
data
data.apply(pd.value_counts).fillna(0)
# useless?
# get_indexer method gives you an index array from an array of possibly non-distinct values into another array of distinct values
to_match = list('cabbca') ; to_match
unique_vals = pd.Series(list('cba')) ; unique_vals
pd.Index(unique_vals).get_indexer(to_match)

### Chapter 6
## Data Loading, Storage, and File Formats
'''
read_csv : Load delimiter data from a file, URL, or file-like object; use ',' as default delimiter 
read_table : Laod delimited data from a file, URL, or file-like object; use '\t' as default delimiter 
read_clipboard : Version of read_table that reads data from the clipboard; useful for converting tables from web pages
read_excel : Read tabular data from an Excel XLS or XLSX file 
read_html : Read all tables found in the given HTML document
read_json
read_pickel
read_sql : Read the results of a SQL query (using SQLAlchemy) as a pandas DataFrame
'''

import os
os.chdir(r'C:\Users\EdwardElric\Desktop\pydata-book-2nd-edition\examples')
!type ex1.csv
pd.read_table(r'ex1.csv',sep =',')
!type ex2.csv
pd.read_csv('ex2.csv', header = None)
# Adding index
pd.read_csv('ex2.csv', names = ['a', 'b', 'c', 'd', 'message'])
# Making some columns index
pd.read_csv('ex2.csv', names = ['a', 'b', 'c', 'd', 'message'], index_col = 'message')
# form a hirearchical(分等级的) index from multiple columns
!type csv_mindex.csv
pd.read_csv('csv_mindex.csv', index_col = ['key1', 'key2'])

list(open('ex3.txt'))
# Passing a regular expression as a delimiter
# The fields here arre separated by a variable amount of whitespace.
# In these cases, a regular expression can be passed as a delimiter.
# Because there are one fewer column name than the number of data rows, read_table infers that the first column should be the  DataFrame's index

pd.read_table('ex3.txt', sep = '\s+')
pd.read_table('ex3.txt') # note this two are different from above
pd.read_csv('ex3.txt')


!type ex4.csv
pd.read_csv('ex4.csv',skiprows = [0,2,3])

!type ex5.csv
# By default, pandas uses a set of commonly occurring sentinels(标记), such as NA and NULL to represent missing values
pd.read_csv('ex5.csv')  # '' and NA are regarded as missing value
# na_values option can take either a list or set of string to consider missing values
pd.read_csv('ex5.csv', na_values = [4]) # value 4 is considered as a missing value
sentinels = {'message': ['foo'], 'something': ['two']}
pd.read_csv('ex5.csv', na_values = sentinels)

### Reading Text Files in Pieces
# make the pandas display settings more compact
pd.options.display.max_rows = 10
pd.read_csv('ex6.csv')

### Writing Data to Text Format
data = pd.read_csv('ex5.csv') ; data
data.to_csv('out.csv')
!type out.csv

# Writing to sys.stdout so it prints the text result to the console
import sys
# Using other delimiters
data.to_csv(sys.stdout, sep = '|')
# Replacing the missing values
data.to_csv(sys.stdout, na_rep = 'NULL')
data.to_csv(sys.stdout, index = False, header = False)
# Writing only specified columns
data.to_csv(sys.stdout, index = False, columns = list('abc'))

# Series also have to_csv method
dates = pd.date_range('1/1/2000', periods = 7) ; dates
ts = pd.Series(np.arange(7), index = dates) ; ts
ts.to_csv(sys.stdout)


### Advanced pandas
### 12.1 Categorical Data

'''
The categorical representation can yiedl significant performance improvements when
you are doing analytics. You can also perform transformations on the categories while
leaving the codes unmodified. Some example transformations that can be made at relati-
vely low cost are: 
- Renaming categories
- Appending a new category without changing the order or position of the existing categories
'''

### Categorical Type in pandas

fruits = ['apple', 'orange', 'apple', 'apple'] * 2
N = len(fruits)
df = pd.DataFrame({'fruit': fruits,
                   'basket_id': np.arange(N),
                   'count': np.random.randint(3,15, size = N),
                   'weight': np.random.uniform(0,4, size = N)},
                  columns = ['basket_id', 'fruit', 'count', 'weight'])
df

# Converting a column of DataFrame into categorical
fruit_cat = df['fruit'].astype('category') ; fruit_cat
'''
The values for `fruit_cat` are not a NumPy array, but an instance of `pandas.Categorical`
'''
type(fruit_cat.values)
# The Categorical object has categories and codes attributes
c = fruit_cat.values
c.categories
c.codes

# Create pandas.Categorical
my_categories = pd.Categorical(['foo', 'bar','baz','foo', 'bar']) ; my_categories

# `from_codes` constructor constructs `Categorical`
categories = ['foo', 'bar', 'baz']
codes = [0,1,2,0,0,1]
my_cat2 = pd.Categorical.from_codes(codes, categories) ; my_cat2

'''Unless explicityly specified, categorical conversions assume no specific ordering of
 the categories. So the categories array may be in a different order depending on the 
 ordering of the input data. When using `from_codes` or any of the other constructors,
 you can indicate that the categories have a meaningful ordering
 '''

# Indicating ordering when creating `Categorical`
ordered_cat = pd.Categorical.from_codes(codes, categories, ordered = True) ; ordered_cat

# Making unordered categorical ordeded
my_cat2
my_cat2.as_ordered()

### Computations with Categoricals
np.random.seed(12345)
draws  = np.random.randn(1000)
draws[:5]
bins = pd.qcut(draws, 4, labels = ['Q1', 'Q2', 'Q3', 'Q4']) ; bins

'''The labeled `bins` categorical does not contain information about the bin edges in the 
data, so we can use `grouby` to extract some summary statistics
'''
pd.Series(draws).groupby(bins).agg(['count','min','max']).reset_index()

## Better performance with categoricals
'''
If you do a lot of analytics on a particular dataset, converting to categorical can yield
substantial overall performance gains. A categorical version of a DataFrame column
will often use significantly less memory, too. Let's conside some Series with 10 mil-
lino elements and a small number of distinct categories'''

N = 100000000
draws = pd.Series(np.random.randn(N))
labels = pd.Series(['foo','bar','baz','qux']*(N//4))
categories = labels. astype('category') # Convert labels to categorical

# Note that labels uses significantly more memory than categories
labels.memory_usage()
categories.memory_usage()
'''
The conversion to category is not free, of course, but it is a  one-time cost
GroupBy operations can be significantly faster with categoricals because the underly-
ing algorithms use the integer-based codes array instead of an array of strings
'''

### Categorical Methods
'''
Series containing categorical data have several special methods similar to the Ser-
ies.str specialized string methods. This also provides convenient access to the cate-
gories and codes.
The special attribute `cat` provides access to categrorical methods
'''
s = pd.Series(list('abdc') * 2)
cat_s = s.astype('category') ; cat_s

cat_s.cat.codes # Returns a pandas Series
cat_s.values.codes # Returns a NumPy array
cat_s.cat.categories # Returns a pandas Series
cat_s.values.categories # Returns a NumPy array

newcat = list('abcde')
# Setting categories
cat_s2 = cat_s.cat.set_categories(newcat)
cat_s2

'''
While it appears that the data is unchanged, the new categories will be reflected in
opeartions that use them. For example, value_conuts respects the categories, if present:
'''
cat_s.value_counts()
cat_s2.value_counts()

'''In large datasets, categoricals are often used as a convenient tool for memeor savings
and better performance. After you filter a large DateFrame of Series, many of the 
`remove_unused_categories` method to trim unobserved categories
'''
cat_s2
cat_s2.cat.remove_unused_categories()


'''
add_categories : Append new categories at end of existing categories
as_ordered : Make categories ordered
as_unordered : Make categories unordered
remove_categories : Remove categories, setting any removed values to null
remove_unused_categories : Remove any category values which do not appear in the data
rename_categories : Remove any categories with indicated set of new category names;
                            cannot change the number of categories
reorder_categories : Behaves like rename_categories, but can alos change the result to have ordered
                      categories
set_categories : Replace the categoires with the indicted set of new categoreis; can add or remove
                 categories                      
'''

#### 12.2 Advanced GroupBy Use
### Group Transforms and "Unwrapped" GroupBys
'''
There is another built-in method called `transform`, which is similar to `apply`
but imposes more constraints on the kind of function you can use:
- It can produce a scalar value to be broadcast to the shape o the group 
- It can produce an object of the same shape as the input group
- It must not mutate(变化，突变) its input
'''
df =pd.DataFrame({'key':['a', 'b', 'c'] * 4,
                  'value': np.arange(12)})
df
g = df.groupby('key').value
g.mean()
'''
Suppose instead we wantd to produce a Sereis of the same shape as df['value']
but with values replaced by the averge groupdy by 'kye'. 
'''
g.transform(lambda x: x.mean())

'''
For built-in aggregation functions, we can pass a string alias as with the GrouBy `agg` method
'''
g.transform('mean')
'''
Like `apply`, `transform` works with functions that return Series, but the result must be
the same size as the input.
'''
g.transform(lambda x: x * 2)
g.apply(lambda x: x * 2)

### Grouped Time Resampling ???

#### 12.3 Techniques for Method Chaining
'''
The `DataFrame.assign` method is a functional alternative to column assgin-
ments often form df[k] = v. Rather than modifying the object in-place, it returns a 
new DataFrame with the indicated modifications. So these statements are equivalent:

# Usual non-functional way
df2 = df.copy()
df2['k'] = v

# Functional assign way
df2 = df.assign(k=v)

Assigning ip-place may execute faster that using `assign`, but `assign` enables easier
method chaining:

result = (df2.assign(col1_demeaned = df2.col1 - df2.col2.mean())
        .groupby('key')
        .col1_demeaned.std())
'''

(df.groupby('key')
    .mean())

### The pipe Method

'''
Consider a sequence of function call:   
    a = f(df, arg1 = v1)
    b = g(a, v2, arg3 = v3)
    c = h(b, argr = v4)
    
You can rewrite this using calls to pipe:
    result = (df.pipe(f, arg=v1)
                .pipe(g, v2, arg3 = v3)
                .pipe(h, arg4 = v4))
    
The statement `f(df)` and `df.pipe(f)` are equivalent, but pipe marke chained invocaiton easier.
'''

### 132. Creating Model Descriptions with Patsy



