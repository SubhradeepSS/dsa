CREATE TABLE Works_With (
    emp_id INT,
    client_id INT,
    total_sales INT,
    CONSTRAINT pk_workswith PRIMARY KEY (emp_id, client_id)
);

CREATE TABLE Branch_Supplier (
    branch_id INT,
    supplier_name VARCHAR(50),
    supply_type VARCHAR(20),
    CONSTRAINT pk_branchsupplier PRIMARY KEY (branch_id, supplier_name)
);

CREATE TABLE Employee (
    emp_id INT PRIMARY KEY,
    first_name VARCHAR(20) NOT NULL,
    last_name VARCHAR(20),
    birth_date DATE,
    sex VARCHAR(1),
    salary INT,
    super_id INT,
    branch_id INT,
    FOREIGN KEY (super_id) REFERENCES Employee (emp_id)
);

CREATE TABLE Branch (
    branch_id INT PRIMARY KEY,
    branch_name VARCHAR(20),
    mgr_id INT,
    mgr_start_date DATE,
    FOREIGN KEY (mgr_id) REFERENCES Employee (emp_id)
);

ALTER TABLE Employee
ADD FOREIGN KEY (branch_id) REFERENCES Branch (branch_id);

CREATE TABLE Client_Table (
    client_id INT PRIMARY KEY,
    client_name VARCHAR(50),
    branch_id INT,
    FOREIGN KEY (branch_id) REFERENCES Branch (branch_id)
);

ALTER TABLE Employee
MODIFY super_id INT NULL;