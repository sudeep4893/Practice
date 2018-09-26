create or replace trigger limitUpdate
before
update of esal, ename
on emp

BEGIN
 DBMS_OUTPUT.PUT_LINE('ENAME or ESAL UPDATED');
END;
/