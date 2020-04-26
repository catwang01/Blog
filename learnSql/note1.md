
[toc]

# Mysql 练习

## 数据导入

```
create database test;
use test;

drop table if exists course;
create table `course`(
    `c_id`  varchar(20),
    `c_name` varchar(20) not null default '',
    `t_id` varchar(20) not null,
    primary key(`c_id`)
) charset=utf8;  

drop table if exists teacher;
create table `teacher`(
    `t_id` varchar(20),
    `t_name` varchar(20) not null default '',
    primary key(`t_id`)
) charset=utf8;

drop table if exists student;
create table `student`(
    `s_id` varchar(20),
    `s_name` varchar(20) not null default '',
    `s_birth` varchar(20) not null default '',
    `s_sex` varchar(10) not null default '',
    primary key(`s_id`)
) charset=utf8;

drop table if exists score;
create table `score`(
    `s_id` varchar(20),
    `c_id`  varchar(20),
    `s_score` int(3),
    primary key(`s_id`,`c_id`)
) charset=utf8;

insert into student values('01' , '赵雷' , '1990-01-01' , '男');
insert into student values('02' , '钱电' , '1990-12-21' , '男');
insert into student values('03' , '孙风' , '1990-05-20' , '男');
insert into student values('04' , '李云' , '1990-08-06' , '男');
insert into student values('05' , '周梅' , '1991-12-01' , '女');
insert into student values('06' , '吴兰' , '1992-03-01' , '女');
insert into student values('07' , '郑竹' , '1989-07-01' , '女');
insert into student values('08' , '王菊' , '1990-01-20' , '女');
insert into student values('09' , '王菊' , '1990-11-20' , '女');

insert into course values('01' , '语文' , '02');
insert into course values('02' , '数学' , '01');
insert into course values('03' , '英语' , '03');

insert into teacher values('01' , '张三');
insert into teacher values('02' , '李四');
insert into teacher values('03' , '王五');

insert into score values('01' , '01' , 80);
insert into score values('01' , '02' , 90);
insert into score values('01' , '03' , 99);
insert into score values('02' , '01' , 70);
insert into score values('02' , '02' , 60);
insert into score values('02' , '03' , 80);
insert into score values('03' , '01' , 80);
insert into score values('03' , '02' , 80);
insert into score values('03' , '03' , 80);
insert into score values('04' , '01' , 50);
insert into score values('04' , '02' , 30);
insert into score values('04' , '03' , 20);
insert into score values('05' , '01' , 76);
insert into score values('05' , '02' , 87);
insert into score values('06' , '01' , 31);
insert into score values('06' , '03' , 34);
insert into score values('07' , '02' , 89);
insert into score values('07' , '03' , 98);
```

## 练习

### 1、查询"01"课程比"02"课程成绩高的学生的信息及课程分数

```
-- 这种情况下用两个相同的表score as a 和 score as b，在一个表中操作比较困难。

select student.*, a.s_score
from score as a, score as b, student
where
    a.s_id = b.s_id and
    a.c_id = 01 and
    b.c_id = 02 and
    a.s_score > b.s_score and
    student.s_id = a.s_id
```

### 2、查询平均成绩大于等于60分的同学的学生编号和学生姓名和平均成绩

```
select student.s_id, student.s_name, AVG(s_score) as average
from
    student join score
        on student.s_id = score.s_id
group by s_id
having AVG(s_score) >=60;
```

```
+------+--------+---------+
| s_id | s_name | average |
+------+--------+---------+
| 01   | 赵雷   | 89.6667 |
| 02   | 钱电   | 70.0000 |
| 03   | 孙风   | 80.0000 |
| 05   | 周梅   | 81.5000 |
| 07   | 郑竹   | 93.5000 |
+------+--------+---------+
```

### 3、查询所有同学的学生编号、学生姓名、选课总数、所有课程的总成绩

```
select student.s_id, student.s_name, count(*) , sum(score.s_score)
from student
    left join score
        on student.s_id = score.s_id
group by student.s_id;
-- 这里使用left join，保留那些在student中存在而在score中不存在的学生（也就是没有选课的学生）?
```

```
+------+--------+------------+-------+--------------+----------+
| s_id | s_name | s_birth    | s_sex | avg(s_score) | count(*) |
+------+--------+------------+-------+--------------+----------+
| 01   | 赵雷   | 1990-01-01 | 男    |      89.6667 |        3 |
| 02   | 钱电   | 1990-12-21 | 男    |      70.0000 |        3 |
| 03   | 孙风   | 1990-05-20 | 男    |      80.0000 |        3 |
| 04   | 李云   | 1990-08-06 | 男    |      33.3333 |        3 |
| 05   | 周梅   | 1991-12-01 | 女    |      81.5000 |        2 |
| 06   | 吴兰   | 1992-03-01 | 女    |      32.5000 |        2 |
| 07   | 郑竹   | 1989-07-01 | 女    |      93.5000 |        2 |
+------+--------+------------+-------+--------------+----------+``` 
```

```
select student.*, avg(s_score), count(*)
from score, student
where student.s_id = score.s_id
group by s_id;
```

### 4、查询"李"姓老师的数量

```
select count(t_id) from teacher where t_name like '李%';
```


### 5、查询学过"张三"老师授课的同学的信息

```
A1:
select a.*
from student a
join score b on a.s_id=b.s_id
where b.c_id in(
    select c_id from course where t_id =(
        select t_id from teacher where t_name = '张三'));

A2:
select student.*
from (
    teacher
    join course
    on teacher.t_id = course.t_id and teacher.t_name = '张三'
    join score
    on course.c_id = score.c_id
    join student
    on score.s_id = student.s_id)
;

A3:
select student.*
from  student
where exists (select * from course, teacher, score where student.s_id = score.s_id and teacher.t_id = course.t_id and teacher.t_name = '张三' and course.c_id = score.c_id);
```

```
select student.*
from score, student
where c_id in (
    select course.c_id
    from teacher, course
    where teacher.t_id = course.t_id
    and teacher.t_name = "张三"
) and score.s_id = student.s_id
```

### 8、查询没学过"张三"老师授课的同学的信息

```
select * from
    student c
    where c.s_id not in(
        select a.s_id from student a join score b on a.s_id=b.s_id where b.c_id in(
            select c_id from course where t_id =(
                select t_id from teacher where t_name = '张三')));
```

-- 查询没有选课的学生
select * from student
where not exists (
    select * from score where student.s_id = score.s_id
);

-- 9、查询学过编号为"01"并且也学过编号为"02"的课程的同学的信息

A1:
select a.* from
    student a,score b,score c
    where a.s_id = b.s_id  and a.s_id = c.s_id and b.c_id='01' and c.c_id='02';

A2:
select student.*
from (select s_id from score where c_id = 01) as a
join (select s_id from score where c_id = 02) as b
on a.s_id = b.s_id
join student on student.s_id = a.s_id;

-- 10、查询学过编号为"01"但是没有学过编号为"02"的课程的同学的信息

A1:

select a.* from
    student a
    where a.s_id in (select s_id from score where c_id='01' ) and a.s_id not in(select s_id from score where c_id='02')

A2:

select student.*
from student
where exists (
    select * from score where score.s_id = student.s_id and score.c_id = 01
    ) and not exists (
    select * from score where score.s_id = student.s_id and score.c_id = 02
    );

-- 11、查询没有学全所有课程的同学的信息

select student.*
from student join (select s_id
    from score
    group by s_id
    having count(*) < (select count(*) from course)) as tmp
    on tmp.s_id = student.s_id
;


-- 12、查询至少有一门课与学号为"01"的同学所学相同的同学的信息

A1:
select * from student where s_id in(
    select distinct a.s_id from score a where a.c_id in(select a.c_id from score a where a.s_id='01')
    );

A2:
select * from student where student.s_id != 01 and exists (
    select * from score where student.s_id = score.s_id and score.c_id in (
        select c_id from score where .s_id='01'
        )
    );

# Question
-- 13、查询和"01"号的同学学习的课程完全相同的其他同学的信息

A1:

select a.* from student a where a.s_id in(
    select distinct s_id from score where s_id!='01' and c_id in(select c_id from score where s_id='01')
    group by s_id
    having count(1)=(select count(1) from score where s_id='01'));

# 这个怕有问题，这个不能剔除那些学习课程大于01号学习课程的学生

A2:
select * from student where s_id not in(
    select tmp.s_id from score
    right join
    (select * from student, (select c_id from score where s_id = 01) as tmp1) as tmp
    on tmp.c_id = score.c_id and tmp.s_id = score.s_id where score.s_score is null);


-- 14、查询没学过"张三"老师讲授的任一门课程的学生姓名

A1
select a.s_name from student a where a.s_id not in (
    select s_id from score where c_id =
                (select c_id from course where t_id =(
                    select t_id from teacher where t_name = '张三'))
                group by s_id);

A2
select s_name from student
where not exists (
    select * from score, course, teacher where teacher.t_name = '张三' and teacher.t_id = course.t_id and course.c_id = score.c_id and score.s_id = student.s_id);

-- 15、查询两门及其以上不及格课程的同学的学号，姓名及其平均成绩

A1
select a.s_id,a.s_name,ROUND(AVG(b.s_score)) from
    student a
    left join score b on a.s_id = b.s_id
    where a.s_id in(
            select s_id from score where s_score<60 GROUP BY  s_id having count(1)>=2)
    GROUP BY a.s_id,a.s_name;

A2
select student.s_name, tmp.*
from student, (
    select score.s_id, AVG(score.s_score) from score where score.s_score < 60 group by score.s_id having count(*) >= 2
    ) as tmp
where tmp.s_id = student.s_id;


-- 16、检索"01"课程分数小于60，按分数降序排列的学生信息

A1

select score.s_id, student.*
from score, student
where score.c_id = 01 and score.s_score < 60 and student.s_id = score.s_id
order by score.s_score desc;


-- 17、按平均成绩从高到低显示所有学生的所有课程的成绩以及平均成绩
#Q:如何将长列表转化为宽列表
A1:
select a.s_id,(select s_score from score where s_id=a.s_id and c_id='01') as 语文,
                (select s_score from score where s_id=a.s_id and c_id='02') as 数学,
                (select s_score from score where s_id=a.s_id and c_id='03') as 英语,
            round(avg(s_score),2) as 平均分 from score a  GROUP BY a.s_id ORDER BY 平均分 DESC;

A2:
select student.s_name,
    max(case c_name when '英语' then s_score else 0 end) as '英语',
    max(case c_name when '语文' then s_score else 0 end) as '语文',
    max(case c_name when '数学' then s_score else 0 end) as '数学',
    AVG(tmp.s_score) as average_score
from (
    select score.s_id, course.c_name, score.s_score from score, course where score.c_id = course.c_id) as tmp, student
where student.s_id = tmp.s_id
group by tmp.s_id
order by AVG(tmp.s_score) desc;


-- 18.查询各科成绩最高分、最低分和平均分：以如下形式显示：课程ID，课程name，最高分，最低分，平均分，及格率，中等率，优良率，优秀率
--及格为>=60，中等为：70-80，优良为：80-90，优秀为：>=90

select a.c_id,b.c_name,MAX(s_score),MIN(s_score),ROUND(AVG(s_score),2),
    ROUND(100*(SUM(case when a.s_score>=60 then 1 else 0 end)/SUM(case when a.s_score then 1 else 0 end)),2) as 及格率,
    ROUND(100*(SUM(case when a.s_score>=70 and a.s_score<=80 then 1 else 0 end)/SUM(case when a.s_score then 1 else 0 end)),2) as 中等率,
    ROUND(100*(SUM(case when a.s_score>=80 and a.s_score<=90 then 1 else 0 end)/SUM(case when a.s_score then 1 else 0 end)),2) as 优良率,
    ROUND(100*(SUM(case when a.s_score>=90 then 1 else 0 end)/SUM(case when a.s_score then 1 else 0 end)),2) as 优秀率
    from score a left join course b on a.c_id = b.c_id GROUP BY a.c_id,b.c_name

-- 19、按各科成绩进行排序，并显示排名(实现不完全)
-- mysql没有rank函数
    select a.s_id,a.c_id,
        @i:=@i +1 as i保留排名,
        @k:=(case when @score=a.s_score then @k else @i end) as rank不保留排名,
        @score:=a.s_score as score
    from (
        select s_id,c_id,s_score from score WHERE c_id='01' GROUP BY s_id,c_id,s_score ORDER BY s_score DESC
)a,(select @k:=0,@i:=0,@score:=0)s
    union
    select a.s_id,a.c_id,
        @i:=@i +1 as i,
        @k:=(case when @score=a.s_score then @k else @i end) as rank,
        @score:=a.s_score as score
    from (
        select s_id,c_id,s_score from score WHERE c_id='02' GROUP BY s_id,c_id,s_score ORDER BY s_score DESC
)a,(select @k:=0,@i:=0,@score:=0)s
    union
    select a.s_id,a.c_id,
        @i:=@i +1 as i,
        @k:=(case when @score=a.s_score then @k else @i end) as rank,
        @score:=a.s_score as score
    from (
        select s_id,c_id,s_score from score WHERE c_id='03' GROUP BY s_id,c_id,s_score ORDER BY s_score DESC
)a,(select @k:=0,@i:=0,@score:=0)s

-- 20、查询学生的总成绩并进行排名
select a.s_id,
    @i:=@i+1 as i,
    @k:=(case when @score=a.sum_score then @k else @i end) as rank,
    @score:=a.sum_score as score
from (select s_id,SUM(s_score) as sum_score from score GROUP BY s_id ORDER BY sum_score DESC)a,
    (select @k:=0,@i:=0,@score:=0)s

-- 21、查询不同老师所教不同课程平均分从高到低显示

select a.t_id,c.t_name,a.c_id,ROUND(avg(s_score),2) as avg_score from course a
    left join score b on a.c_id=b.c_id
    left join teacher c on a.t_id=c.t_id
    GROUP BY a.c_id,a.t_id,c.t_name ORDER BY avg_score DESC;

select teacher.t_name, teacher.t_id, score.c_id, AVG(score.s_score)
from score, course, teacher
where score.c_id = course.c_id and teacher.t_id = course.t_id
group by score.c_id
order by AVG(score.s_score) desc;


-- 22、查询所有课程的成绩第2名到第3名的学生信息及该课程成绩

            select d.*,c.排名,c.s_score,c.c_id from (
                select a.s_id,a.s_score,a.c_id,@i:=@i+1 as 排名 from score a,(select @i:=0)s where a.c_id='01'
            )c
            left join student d on c.s_id=d.s_id
            where 排名 BETWEEN 2 AND 3
            UNION
            select d.*,c.排名,c.s_score,c.c_id from (
                select a.s_id,a.s_score,a.c_id,@j:=@j+1 as 排名 from score a,(select @j:=0)s where a.c_id='02'
            )c
            left join student d on c.s_id=d.s_id
            where 排名 BETWEEN 2 AND 3
            UNION
            select d.*,c.排名,c.s_score,c.c_id from (
                select a.s_id,a.s_score,a.c_id,@k:=@k+1 as 排名 from score a,(select @k:=0)s where a.c_id='03'
            )c
            left join student d on c.s_id=d.s_id
            where 排名 BETWEEN 2 AND 3;


-- 23、统计各科成绩各分数段人数：课程编号,课程名称,[100-85],[85-70],[70-60],[0-60]及所占百分比

        select distinct f.c_name,a.c_id,b.`85-100`,b.百分比,c.`70-85`,c.百分比,d.`60-70`,d.百分比,e.`0-60`,e.百分比 from score a
                left join (select c_id,SUM(case when s_score >85 and s_score <=100 then 1 else 0 end) as `85-100`,
                                            ROUND(100*(SUM(case when s_score >85 and s_score <=100 then 1 else 0 end)/count(*)),2) as 百分比
                                from score GROUP BY c_id)b on a.c_id=b.c_id
                left join (select c_id,SUM(case when s_score >70 and s_score <=85 then 1 else 0 end) as `70-85`,
                                            ROUND(100*(SUM(case when s_score >70 and s_score <=85 then 1 else 0 end)/count(*)),2) as 百分比
                                from score GROUP BY c_id)c on a.c_id=c.c_id
                left join (select c_id,SUM(case when s_score >60 and s_score <=70 then 1 else 0 end) as `60-70`,
                                            ROUND(100*(SUM(case when s_score >60 and s_score <=70 then 1 else 0 end)/count(*)),2) as 百分比
                                from score GROUP BY c_id)d on a.c_id=d.c_id
                left join (select c_id,SUM(case when s_score >=0 and s_score <=60 then 1 else 0 end) as `0-60`,
                                            ROUND(100*(SUM(case when s_score >=0 and s_score <=60 then 1 else 0 end)/count(*)),2) as 百分比
                                from score GROUP BY c_id)e on a.c_id=e.c_id
                left join course f on a.c_id = f.c_id

-- 24、查询学生平均成绩及其名次

        select a.s_id,
                @i:=@i+1 as '不保留空缺排名',
                @k:=(case when @avg_score=a.avg_s then @k else @i end) as '保留空缺排名',
                @avg_score:=avg_s as '平均分'
        from (select s_id,ROUND(AVG(s_score),2) as avg_s from score GROUP BY s_id)a,(select @avg_score:=0,@i:=0,@k:=0)b;
-- 25、查询各科成绩前三名的记录
            -- 1.选出b表比a表成绩大的所有组
            -- 2.选出比当前id成绩大的 小于三个的
        select a.s_id,a.c_id,a.s_score from score a
            left join score b on a.c_id = b.c_id and a.s_score<b.s_score
            group by a.s_id,a.c_id,a.s_score HAVING COUNT(b.s_id)<3
            ORDER BY a.c_id,a.s_score DESC

-- 26、查询每门课程被选修的学生数

        select c_id,count(s_id) from score a GROUP BY c_id

-- 27、查询出只有两门课程的全部学生的学号和姓名
        select s_id,s_name from student where s_id in(
                select s_id from score GROUP BY s_id HAVING COUNT(c_id)=2);

-- 28、查询男生、女生人数

select s_sex, count(*)
from student
group by s_sex

-- 29、查询名字中含有"风"字的学生信息

select * from student where s_name like '%风%';

-- 30、查询同名同性学生名单，并统计同名人数

select a.s_name,a.s_sex,count(*)
from student a
JOIN student b on a.s_id !=b.s_id and a.s_name = b.s_name and a.s_sex = b.s_sex
GROUP BY a.s_name,a.s_sex

select s_name, s_sex, count(*) from student group by s_name having count(*)>1;

-- 31、查询1990年出生的学生名单

select s_name from student where s_birth like '1990%'

-- 32、查询每门课程的平均成绩，结果按平均成绩降序排列，平均成绩相同时，按课程编号升序排列

select c_id,ROUND(AVG(s_score),2) as avg_score
from score
GROUP BY c_id
ORDER BY avg_score DESC,c_id ASC

-- 33、查询平均成绩大于等于85的所有学生的学号、姓名和平均成绩

select student.s_id, student.s_name, round(avg(score.s_score), 2)
from student, score
where student.s_id = score.s_id
group by student.s_id
having avg(score.s_score) >= 85

-- 34、查询课程名称为"数学"，且分数低于60的学生姓名和分数

select student.s_name, score.s_score
from student, score, course
where course.c_name = '数学' and score.s_score < 60 and student.s_id = score.s_id and score.c_id = course.c_id;

-- 35、查询所有学生的课程及分数情况；

select a.s_id,a.s_name,
    SUM(case c.c_name when '语文' then b.s_score else 0 end) as '语文',
    SUM(case c.c_name when '数学' then b.s_score else 0 end) as '数学',
    SUM(case c.c_name when '英语' then b.s_score else 0 end) as '英语',
    SUM(b.s_score) as  '总分'
from student a left join score b on a.s_id = b.s_id
left join course c on b.c_id = c.c_id
    GROUP BY a.s_id,a.s_name

 -- 36、查询任何一门课程成绩在70分以上的姓名、课程名称和分数；
select a.s_name,b.c_name,c.s_score
from course b
    left join score c on b.c_id = c.c_id
    left join student a on a.s_id=c.s_id
where c.s_score > 70

select student.s_name, course.c_name, score.s_score
from score, student, course
where
    score.s_score > 70 and
    student.s_id = score.s_id and
    course.c_id = score.c_id

--38、查询课程编号为01且课程成绩60分以上的学生的学号和姓名；
select a.s_id,b.s_name from score a LEFT JOIN student b on a.s_id = b.s_id
    where a.c_id = '01' and a.s_score > 60

select student.s_id, student.s_name
from score, student
where
    score.c_id = 01 and
    score.s_score > 60 and
    student.s_id = score.s_id;

-- 39、求每门课程的学生人数
        select count(*) from score GROUP BY c_id;

        select course.c_name, score.c_id, count(*)
        from score
            join course
                on score.c_id = course.c_id
        group by c_id

-- 40、查询选修"张三"老师所授课程的学生中，成绩最高的学生信息及其成绩


        -- 查询老师id
        select c_id from course c,teacher d where c.t_id=d.t_id and d.t_name='张三'
        -- 查询最高分（可能有相同分数）
        select MAX(s_score) from score where c_id='02'
        -- 查询信息
        select a.*,b.s_score,b.c_id,c.c_name from student a
            LEFT JOIN score b on a.s_id = b.s_id
            LEFT JOIN course c on b.c_id=c.c_id
            where b.c_id =(select c_id from course c,teacher d where c.t_id=d.t_id and d.t_name='张三')
            and b.s_score in (select MAX(s_score) from score where c_id='02')

    A2 #Q
    select student.*, score.*
    from score, course, teacher, student
    where
        course.t_id = teacher.t_id and
        course.c_id = score.c_id and
        student.s_id = score.s_id and
        teacher.t_name = '张三'
    having score.s_score = max(score.s_score);
    # 这里的having没有接group，相当于在整个查询结果中筛选
    # having中出现的字段需要在查询结果中，如果查询结果中不含s_score字段，那么上述语句会报错
    # 这里的having不能用where 代替，因为where的执行顺序在聚合函数之前，因此where语句中不能使用聚合函数


#Q
-- 42、查询每门功课成绩最好的前两名
select a.s_id, a.c_id, a.s_score
from score as a
where (
    select COUNT(1)
    from score as b
    where
        b.c_id=a.c_id and
        b.s_score>=a.s_score
        ) <= 2
ORDER BY a.c_id


-- 43、统计每门课程的学生选修人数（超过5人的课程才统计）。要求输出课程号和选修人数，查询结果按人数降序排列，若人数相同，按课程号升序排列

select c_id, count(*) as total
from score
GROUP BY c_id
HAVING total > 5
ORDER BY total, c_id ASC


-- 45、查询选修了全部课程的学生信息

select student.*
from student, score
where student.s_id = score.s_id
group by score.s_id
having count(*) = (select count(*) from course)

--46、查询各学生的年龄
    -- 按照出生日期来算，当前月日 < 出生年月的月日则，年龄减一

    select s_birth, (DATE_FORMAT(NOW(),'%Y')-DATE_FORMAT(s_birth,'%Y') -
                (case when DATE_FORMAT(NOW(),'%m%d')>DATE_FORMAT(s_birth,'%m%d') then 0 else 1 end)) as age
        from student;


-- 47、查询本周过生日的学生
    select * from student where WEEK(DATE_FORMAT(NOW(),'%Y%m%d'))=WEEK(s_birth)
    select * from student where YEARWEEK(s_birth)=YEARWEEK(DATE_FORMAT(NOW(),'%Y%m%d'))

    select WEEK(DATE_FORMAT(NOW(),'%Y%m%d'))

-- 48、查询下周过生日的学生
    select * from student where WEEK(DATE_FORMAT(NOW(),'%Y%m%d'))+1 =WEEK(s_birth)

-- 49、查询本月过生日的学生

    select * from student where MONTH(DATE_FORMAT(NOW(),'%Y%m%d')) =MONTH(s_birth)

-- 50、查询下月过生日的学生
    select * from student where MONTH(DATE_FORMAT(NOW(),'%Y%m%d'))+1 =MONTH(s_birth)
```

