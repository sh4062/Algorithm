--sql3.7.9 NOWCODER
--查找最晚入职员工的所有信息
select * from employees
where hire_date =
(select max(hire_date) from employees);
--查找入职员工时间排名倒数第三的员工所有信息
SELECT * FROM employees ORDER BY hire_date DESC LIMIT 2,1;
--查找各个部门当前(to_date='9999-01-01')领导当前薪水详情以及其对应部门编号dept_no
SELECT s.*, d.dept_no FROM salaries s ,  dept_manager d
 
WHERE s.to_date='9999-01-01'
 
AND d.to_date='9999-01-01'
 
AND s.emp_no = d.emp_no;
--查找所有已经分配部门的员工的last_name和first_name
select e.last_name,e.first_name,d.dept_no from employees e,dept_emp d
where d.emp_no=e.emp_no
--SELECT e.last_name, e.first_name, d.dept_no FROM dept_emp d NATURAL JOIN employees e;
--inner join是内连接,显示符合连接条件的记录 ex:select select_list from table1 inner join tabl2 on table1.column1=table2.column1
-- natural join:指明了两表进行自然连接，并且连接是基于两表中所有同名字段的。

--查找所有员工的last_name和first_name以及对应部门编号dept_no，也包括展示没有分配具体部门的员工
SELECT e.last_name, e.first_name, d.dept_no FROM employees e LEFT JOIN dept_emp d on e.emp_no = d.emp_no;

--查找所有员工入职时候的薪水情况，给出emp_no以及salary， 并按照emp_no进行逆序
SELECT e.emp_no, s.salary FROM employees e inner JOIN salaries s on e.emp_no = s.emp_no and e.hire_date = s.from_date order by e.emp_no desc;

--查找薪水涨幅超过15次的员工号emp_no以及其对应的涨幅次数t
SELECT emp_no, COUNT(emp_no) AS t FROM salaries 
GROUP BY emp_no HAVING t > 15
--WHERE语句在GROUP BY语句之前；SQL会在分组之前计算WHERE语句。   
--HAVING语句在GROUP BY语句之后；SQL会在分组之后计算HAVING语句。

--找出所有员工当前(to_date='9999-01-01')具体的薪水salary情况，对于相同的薪水只显示一次,并按照逆序显示
SELECT DISTINCT salary FROM salaries WHERE to_date = '9999-01-01' ORDER BY salary DESC;

--获取所有部门当前manager的当前薪水情况，给出dept_no, emp_no以及salary，当前表示to_date='9999-01-01'
SELECT d.dept_no,d.emp_no, s.salary FROM salaries s inner join  dept_manager d WHERE s.emp_no = d.emp_no AND s.to_date = '9999-01-01' AND d.to_date = '9999-01-01';

--获取所有非manager的员工emp_no
SELECT emp_no FROM employees  where emp_no not in (SELECT emp_no FROM dept_manager);

--获取所有员工当前的manager，如果当前的manager是自己的话结果不显示，当前表示to_date='9999-01-01'。
SELECT e.emp_no,m.emp_no FROM dept_emp e,dept_manager m WHERE e.dept_no =m.dept_no AND e.emp_no<>m.emp_no AND e.to_date='9999-01-01' AND m.to_date='9999-01-01';
--<>微软的MS SQL中，只能识别‘<>’为不等于的逻辑运算，不能正确识别'!='

--获取所有部门中当前员工薪水最高的相关信息，给出dept_no, emp_no以及其对应的salary
SELECT e.dept_no,e.emp_no,s.salary FROM dept_emp e inner join salaries s on e.emp_no = s.emp_no WHERE e.to_date = '9999-01-01' AND s.to_date = '9999-01-01'
GROUP BY e.dept_no having MAX(s.salary) ;

--从titles表获取按照title进行分组，每组个数大于等于2，给出title以及对应的数目t。
SELECT title,count(title) FROM titles GROUP BY title;

--从titles表获取按照title进行分组，每组个数大于等于2，给出title以及对应的数目t。注意对于重复的emp_no进行忽略。
SELECT title, COUNT(DISTINCT emp_no) AS t FROM titles
GROUP BY title HAVING t >= 2;

--查找employees表所有emp_no为奇数，且last_name不为Mary的员工信息，并按照hire_date逆序排列
SELECT * FROM employees WHERE (emp_no%2)<>0 AND last_name<>"Mary" Order By hire_date DESC;

--统计出当前各个title类型对应的员工当前薪水对应的平均工资。结果给出title以及平均工资avg。
SELECT t.title,avg(s.salary) FROM titles t inner join salaries s on t.emp_no = s.emp_no WHERE t.to_date = '9999-01-01' AND s.to_date = '9999-01-01'
GROUP BY t.title;

--获取当前（to_date='9999-01-01'）薪水第二多的员工的emp_no以及其对应的薪水salary
SELECT emp_no,salary FROM salaries ORDER BY salary DESC LIMIT 1,1;

--查找当前薪水(to_date='9999-01-01')排名第二多的员工编号emp_no、薪水salary、last_name以及first_name，不准使用order by
SELECT e.emp_no, MAX(s.salary) AS salary, e.last_name, e.first_name 
FROM employees AS e INNER JOIN salaries AS s 
ON e.emp_no = s.emp_no
WHERE s.to_date = '9999-01-01'
AND s.salary NOT IN (SELECT MAX(salary) FROM salaries WHERE to_date = '9999-01-01')

--查找所有员工的last_name和first_name以及对应的dept_name，也包括暂时没有分配部门的员工
SELECT e.last_name,e.first_name,de.dept_name FROM (employees e left join dept_emp d on e.emp_no = d.emp_no )left join departments de on d.dept_no = de.dept_no ;

--查找员工编号emp_now为10001其自入职以来的薪水salary涨幅值growth
SELECT (
    (SELECT salary FROM salaries WHERE emp_no = 10001 ORDER BY to_date DESC LIMIT 1)-
    (SELECT salary FROM salaries WHERE emp_no = 10001 ORDER BY to_date ASC LIMIT 1)
) AS growth

--******查找所有员工自入职以来的薪水涨幅情况，给出员工编号emp_noy以及其对应的薪水涨幅growth，并按照growth进行升序
SELECT sCurrent.emp_no, (sCurrent.salary-sStart.salary) AS growth
FROM (SELECT s.emp_no, s.salary FROM employees e, salaries s WHERE e.emp_no = s.emp_no AND s.to_date = '9999-01-01') AS sCurrent,
(SELECT s.emp_no, s.salary FROM employees e, salaries s WHERE e.emp_no = s.emp_no AND s.from_date = e.hire_date) AS sStart
WHERE sCurrent.emp_no = sStart.emp_no
ORDER BY growth

--统计各个部门对应员工涨幅的次数总和，给出部门编码dept_no、部门名称dept_name以及次数sum
SELECT de.dept_no, dp.dept_name, COUNT(s.salary) AS sum 
FROM (dept_emp AS de INNER JOIN salaries AS s ON de.emp_no = s.emp_no) 
INNER JOIN departments AS dp ON de.dept_no = dp.dept_no 
GROUP BY de.dept_no;

--*****对所有员工的当前(to_date='9999-01-01')薪水按照salary进行按照1-N的排名，相同salary并列且按照emp_no升序排列
select s1.emp_no,s1.salary,count(distinct s2.salary)--用小于等于它的数量作为ｒａｎｋ
from salaries as s1 ,salaries as s2
where s1.to_date='9999-01-01'
    and s2.to_date='9999-01-01'
    and s1.salary<=s2.salary
group by s1.emp_no
order by s1.salary desc,s1.emp_no asc

--获取所有非manager员工当前的薪水情况，给出dept_no、emp_no以及salary ，当前表示to_date='9999-01-01
SELECT de.dept_no,e.emp_no,s.salary from (employees e inner join salaries s on e.emp_no=s.emp_no AND s.to_date = '9999-01-01')inner join dept_emp de on de.emp_no = s.emp_no 
where e.emp_no not in (SELECT emp_no FROM dept_manager WHERE to_date = '9999-01-01');

--获取员工其当前的薪水比其manager当前薪水还高的相关信息，当前表示to_date='9999-01-01',
select aa.emp_no ,bb.emp_no, aa.salary, bb.salary
from
(dept_emp join salaries on dept_emp.emp_no = salaries.emp_no and dept_emp.to_date = salaries.to_date and dept_emp.to_date='9999-01-01')
as aa join
(dept_manager join salaries on dept_manager.emp_no = salaries.emp_no and dept_manager.to_date = salaries.to_date and dept_manager.to_date='9999-01-01')
as bb
on aa.dept_no = bb.dept_no and aa.salary > bb.salary

--汇总各个部门当前员工的title类型的分配数目，结果给出部门编号dept_no、dept_name、其当前员工所有的title以及该类型title对应的数目count
SELECT de.dept_no,d.dept_name,t.title,count(t.title)as count
FROM (dept_emp de  inner join titles t on de.emp_no = t.emp_no and t.to_date = '9999-01-01' and de.to_date = '9999-01-01')inner join departments d on de.dept_no=d.dept_no
GROUP BY de.dept_no, t.title
--关键在于用 GROUP BY 同时对 de.dept_no 和 t.title 进行分组

--.....给出每个员工每年薪水涨幅超过5000的员工编号emp_no、薪水变更开始日期from_date以及薪水涨幅值salary_growth，并按照salary_growth逆序排列。
SELECT s2.emp_no, s2.from_date, (s2.salary - s1.salary) AS salary_growth
FROM salaries AS s1, salaries AS s2
WHERE s1.emp_no = s2.emp_no 
AND salary_growth > 5000
AND (strftime("%Y",s2.to_date) - strftime("%Y",s1.to_date) = 1 
     OR strftime("%Y",s2.from_date) - strftime("%Y",s1.from_date) = 1 )
ORDER BY salary_growth DESC

--查找描述信息中包括robot的电影对应的分类名称以及电影数目，而且还需要该分类对应电影数量>=5部
--链接：https://www.nowcoder.com/questionTerminal/3a303a39cc40489b99a7e1867e6507c5
--来源：牛客网

--1、找到对应电影数量>=5的所有分类，建立成虚表cc：(select category_id, count(film_id) as category_num from  film_category  group by category_id having count(film_id)>=5)
-- as cc
--2、设定限制条件 f.description like '%robot%'
--3、在表cc、f、fc、c中查找包括robot的电影对应的分类名称和对应的电影数目。
SELECT c.name, COUNT(fc.film_id) FROM
 (select category_id, COUNT(film_id) AS category_num FROM
     film_category  GROUP BY category_id HAVING count(film_id)>=5) AS cc,
 film AS f, film_category AS fc, category AS c
WHERE  f.description LIKE '%robot%'
AND f.film_id = fc.film_id
AND c.category_id = fc.category_id
AND c.category_id=cc.category_id

--使用join查询方式找出没有分类的电影id以及名称
SELECT f.film_id, f.title FROM film f LEFT JOIN film_category fc
ON f.film_id = fc.film_id WHERE fc.category_id IS NULL

--使用子查询的方式找出属于Action分类的所有电影对应的title,description
SELECT f.title, f.description FROM (film f LEFT JOIN film_category fc
ON f.film_id = fc.film_id) join category c on c.category_id = fc.category_id WHERE c.name ='Action';

--???获取select * from employees对应的执行计划
EXPLAIN SELECT * FROM employees;

--将employees表的所有员工的last_name和first_name拼接起来作为Name，中间以一个空格区分
--不同数据库连接字符串的方法不完全相同，MySQL、SQL Server、Oracle等数据库支持CONCAT方法，而本题所用的SQLite数据库只支持用连接符号"||"来连接字符串
SELECT last_name||" "||first_name AS Name FROM employees

--创建一个actor表
CREATE TABLE `actor` (
`actor_id` smallint(5) NOT NULL,
`first_name` varchar(45)	 NOT NULL,
`last_name` varchar(45)	 NOT NULL,
`last_update` timestamp NOT NULL DEFAULT(datetime('now','localtime')),
PRIMARY KEY (`actor_id`));

--对于表actor批量插入如下数据
INSERT INTO actor VALUES(1,'PENELOPE','GUINESS','2006-02-15 12:34:33'),
(2,'NICK','WAHLBERG','2006-02-15 12:34:33');

--对于表actor批量插入如下数据,如果数据已经存在，请忽略，不使用replace操作
--在 SQLite 中，用 INSERT OR IGNORE 来插入记录，或忽略插入与表内UNIQUE字段都相同的记录
INSERT OR IGNORE INTO actor VALUES('3','ED','CHASE'	,'2006-02-15 12:34:33');

--创建一个actor_name表，将actor表中的所有first_name以及last_name导入改表。 actor_name表结构如下：
create table actor_name(
    first_name varchar(45) not null,   
    last_name varchar(45) not null 
);
insert into actor_name select first_name,last_name from actor;

--对first_name创建唯一索引uniq_idx_firstname，对last_name创建普通索引idx_lastname
CREATE UNIQUE INDEX uniq_idx_firstname ON actor(first_name);
CREATE INDEX idx_lastname ON actor(last_name);

--针对actor表创建视图actor_name_view，只包含first_name以及last_name两列，并对这两列重新命名，first_name为first_name_v，last_name修改为last_name_v：
CREATE VIEW actor_name_view AS
SELECT first_name AS first_name_v, last_name AS last_name_v
FROM actor;
--http://www.w3school.com.cn/sql/sql_view.asp

--针对salaries表emp_no字段创建索引idx_emp_no，查询emp_no为10005, 使用强制索引。
SELECT * FROM salaries INDEXED BY idx_emp_no WHERE emp_no = 10005
SELECT * FROM salaries FORCE INDEX idx_emp_no WHERE emp_no = 10005
--MYSQL中强制索引查询使用：FORCE INDEX(indexname);
--SQLite中强制索引查询使用：INDEXED BY indexname;

--现在在last_update后面新增加一列名字为create_date, 类型为datetime, NOT NULL
ALTER TABLE actor ADD create_date datetime NOT NULL DEFAULT '0000-00-00 00:00:00';

--构造一个触发器audit_log，在向employees_test表中插入一条数据的时候，触发插入相关的数据到audit中。
--1.创建触发器使用语句：CREATE TRIGGER trigname;
--2.指定触发器触发的事件在执行某操作之前还是之后，使用语句：BEFORE/AFTER [INSERT/UPDATE/ADD] ON tablename
--3.触发器触发的事件写在BEGIN和END之间；
--4.触发器中可以通过NEW获得触发事件之后2对应的tablename的相关列的值，OLD获得触发事件之前的2对应的tablename的相关列的值
CREATE TRIGGER audit_log AFTER INSERT ON employees_test
BEGIN
    INSERT INTO audit VALUES(NEW.ID,NEW.NAME);
END;

--删除emp_no重复的记录，只保留最小的id对应的记录。
DELETE FROM titles_test WHERE id NOT IN 
(SELECT MIN(id) FROM titles_test GROUP BY emp_no)

--将所有to_date为9999-01-01的全部更新为NULL,且 from_date更新为2001-01-01。
UPDATE titles_test SET to_date = NULL,from_date = '2001-01-01'  WHERE to_date = '9999-01-01' ;

--将id=5以及emp_no=10001的行数据替换成id=5以及emp_no=10005,其他数据保持不变，使用replace实现。
UPDATE titles_test SET emp_no = REPLACE(emp_no,10001,10005) WHERE id = 5;
--OR
REPLACE INTO titles_test VALUES (5, 10005, 'Senior Engineer', '1986-06-26', '9999-01-01')

--将titles_test表名修改为titles_2017。
 ALTER TABLE titles_test RENAME TO titles_2017;

 --在audit表上创建外键约束，其emp_no对应employees_test表的主键id。
DROP TABLE audit;
CREATE TABLE audit(
    EMP_no INT NOT NULL,
    create_date datetime NOT NULL,
    FOREIGN KEY(EMP_no) REFERENCES employees_test(ID));

--视图,如何获取emp_v和employees有相同的数据？
SELECT em.* FROM employees em, emp_v ev WHERE em.emp_no = ev.emp_no;

--将所有获取奖金的员工当前的薪水增加10%。
Update salaries
SET salary = salary * 1.1
WHERE emp_no IN
(SELECT s.emp_no FROM salaries AS s INNER JOIN emp_bonus AS eb 
ON s.emp_no = eb.emp_no AND s.to_date = '9999-01-01')

--针对库中的所有表生成select count(*)对应的SQL语句
SELECT "select count(*) from " || name || ";" AS cnts
FROM sqlite_master WHERE type = 'table';

--将employees表中的所有员工的last_name和first_name通过(')连接起来。
SELECT e.last_name|| "'" ||e.first_name  AS name
FROM employees e;

--查找字符串'10,A,B' 中逗号','出现的次数cnt。
select length('10,A,B') -length(replace('10,A,B',",",""));

--获取Employees中的first_name，查询按照first_name最后两个字母，按照升序进行排列
SELECT first_name FROM employees ORDER BY substr(first_name,-2);

--按照dept_no进行汇总，属于同一个部门的emp_no按照逗号进行连接，结果给出dept_no以及连接出的结果employees group_concat
SELECT dept_no,group_concat(emp_no) as employees FROM dept_emp
group by dept_no;

--查找排除当前最大、最小salary之后的员工的平均工资avg_salary。
SELECT avg(salary) FROM salaries WHERE to_date = '9999-01-01' AND
salary NOT IN (SELECT max(salary) FROM salaries  ) AND (SELECT min(salary) FROM salaries  ) ;

--分页查询employees表，每5行一页，返回第2页的数据
--方法一：利用 LIMIT 和 OFFSET 关键字。LIMIT 后的数字代表返回几条记录，OFFSET 后的数字代表从第几条记录开始返回（第一条记录序号为0），也可理解为跳过多少条记录后开始返回。
SELECT * FROM employees LIMIT 5 OFFSET 5
--OR
SELECT * FROM employees LIMIT 5,5

--获取所有员工的emp_no、部门编号dept_no以及对应的bonus类型btype和recevied，没有分配具体的员工不显示
SELECT em.emp_no, de.dept_no, eb.btype, eb.recevied
FROM employees AS em INNER JOIN dept_emp AS de
ON em.emp_no = de.emp_no
LEFT JOIN emp_bonus AS eb 
ON de.emp_no = eb.emp_no;

--使用含有关键字exists查找未分配具体部门的员工的所有信息。
SELECT * FROM employees WHERE NOT EXISTS 
(SELECT emp_no FROM dept_emp WHERE emp_no = employees.emp_no);

--获取employees中的行数据，且这些行也存在于emp_v中。注意不能使用intersect关键字。
SELECT * FROM emp_v;

--给出emp_no、first_name、last_name、奖金类型btype、对应的当前薪水情况salary以及奖金金额bonus。 bonus类型btype为1其奖金为薪水salary的10%，btype为2其奖金为薪水的20%，其他类型均为薪水的30%。 当前薪水表示to_date='9999-01-01'
SELECT em.emp_no, em.first_name,em.last_name, eb.btype, s.salary,
(CASE eb.btype 
 WHEN 1 THEN s.salary * 0.1
 WHEN 2 THEN s.salary * 0.2
 ELSE s.salary * 0.3 END) AS bonus
FROM employees AS em 
INNER JOIN salaries AS s 
ON em.emp_no = s.emp_no AND s.to_date='9999-01-01'
INNER JOIN emp_bonus AS eb 
ON s.emp_no = eb.emp_no;
--CASE的使用

--按照salary的累计和running_total，其中running_total为前两个员工的salary累计和，其他以此类推。 具体结果如下Demo展示。。
select a.emp_no, a.salary, sum(b.salary)
from salaries as a, salaries as b
where b.emp_no <= a.emp_no
and a.to_date = '9999-01-01'
and b.to_date = '9999-01-01'
group by a.emp_no
order by a.emp_no asc

--对于employees表中，给出奇数行的first_name
SELECT E1.first_name
FROM employees E1
WHERE(SELECT COUNT(*) FROM employees E2 WHERE E1.first_name>=E2.first_name)%2=1;



 

