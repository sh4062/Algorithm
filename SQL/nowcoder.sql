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
