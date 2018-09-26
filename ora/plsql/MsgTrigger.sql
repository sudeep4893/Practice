create or replace trigger MsgTrigger
after
insert or delete or update
on emp

BEGIN
  IF INSERTING THEN
    DBMS_OUTPUT.PUT_LINE('I am watching your insert');
  ELSIF UPDATING THEN
    DBMS_OUTPUT.PUT_LINE('I am watching your update');
  ELSIF DELETING THEN
    DBMS_OUTPUT.PUT_LINE('I am watching your delete');
  END IF;
END;
/




