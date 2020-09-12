SELECT * FROM Employee;
SELECT * FROM Branch;
SELECT * FROM Client_Table;
SELECT * FROM Works_With;
SELECT * FROM Branch_Supplier;

SELECT * FROM Employee WHERE super_id=100;
SELECT emp_id FROM Employee WHERE branch_id=2;
SELECT emp_id, first_name, last_name FROM Employee WHERE salary BETWEEN 75000 AND 100000;

SELECT branch_id FROM Branch WHERE mgr_start_date < '2000-01-01';

SELECT client_id, client_name FROM Client_Table WHERE branch_id = 2 OR branch_id = 3;

SELECT branch_id FROM Branch_Supplier WHERE supply_type = 'paper';
SELECT supplier_name FROM Branch_Supplier WHERE supply_type IN ('Paper', 'Custom Forms');

SELECT * FROM Works_With ORDER BY total_sales;