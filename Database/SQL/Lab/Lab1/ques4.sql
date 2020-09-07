CREATE TABLE Car (
    serial_no INT PRIMARY KEY,
    model VARCHAR(20),
    manufacturer VARCHAR(50),
    price INT
);

CREATE TABLE Options_ (
    serial_no INT,
    option_name VARCHAR(50),
    price INT,
    FOREIGN KEY (serial_no) REFERENCES Car(serial_no)
);

CREATE TABLE Salesperson (
    salesperson_id INT PRIMARY KEY,
    name_ VARCHAR(20),
    phone VARCHAR(15),
);

CREATE TABLE Sales (
    salesperson_id INT,
    serial_no INT,
    date_ DATE,
    sale_price INT,
    FOREIGN KEY (serial_no) REFERENCES Car(serial_no),
    FOREIGN KEY (salesperson_id) REFERENCES Salesperson(salesperson_id)
);


-- 1
SELECT serial_no, manufacturer, price FROM Car WHERE serial_no IN 
(SELECT serial_no FROM Sales WHERE salesperson_id IN 
(SELECT salesperson_id FROM Salesperson WHERE name_='John'));

-- 2
SELECT car_table.serial_no, car_table.model FROM Car car_table
LEFT JOIN Options_ options_table ON car_table.serial_no = options_table.serial_no
WHERE options_table.serial_no IS NULL;

-- 3
SELECT car_table.serial_no, car_table.model FROM Car car_table
LEFT JOIN Options_ options_table ON car_table.serial_no = options_table.serial_no
WHERE options_table.serial_no IS NOT NULL;

-- 4
UPDATE Salesperson
SET phone = '' WHERE salesperson_id = ''