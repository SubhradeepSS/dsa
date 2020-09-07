CREATE TABLE SalesPerson (
    ssn INT PRIMARY KEY,
    name_ VARCHAR(50),
    start_year VARCHAR(4),
    dept_no INT
);

CREATE TABLE Trip (
    trip_id INT PRIMARY KEY,
    ssn INT,
    from_city VARCHAR(20),
    to_city VARCHAR(20),
    departure_date DATE,
    return_date DATE,
    FOREIGN KEY (ssn) REFERENCES SalesPerson(ssn)
);

CREATE TABLE Salerep_Expense (
    trip_id INT,
    amount INT,
    expense_type VARCHAR(6),
    FOREIGN KEY (trip_id) REFERENCES Trip(trip_id),
    CHECK (expense_type IN ('TRAVEL', 'STAY', 'FOOD'))
);

-- 1
SELECT * FROM Trip WHERE trip_id IN 
(SELECT trip_id FROM Salerep_Expense WHERE amount > 2000);

-- 2
SELECT ssn FROM SalesPerson WHERE ssn IN 
(SELECT ssn FROM Trip GROUP BY to_city HAVING COUNT(to_city) > 1);

-- 3
SELECT SUM(amount) FROM Salerep_Expense WHERE trip_id IN 
(SELECT trip_id FROM Trip WHERE ssn=1000);

-- 4
SELECT * FROM SalesPerson ORDER BY name_;
