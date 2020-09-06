CREATE TABLE Doctor (
    username VARCHAR(30) PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    phone NUMERIC,
    email VARCHAR(20) NOT NULL,
    gender VARCHAR(6),
    department VARCHAR(15) NOT NULL,
    attendance INT,
    salary INT,
    status VARCHAR(10),
    CHECK (gender IN ('Male', 'Female', 'Other')),
    CHECK (status IN ('Active', 'Not Active'))
);