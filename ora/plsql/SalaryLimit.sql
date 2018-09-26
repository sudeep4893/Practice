create or replace trigger SalaryLimit
before
update of esal
on emp
FOR EACH ROW
WHEN (new.esal < 3000 OR new.esal > 10000)

BEGIN
    raise_application_error(-20001, 'SALARY out of range');
END;
/

