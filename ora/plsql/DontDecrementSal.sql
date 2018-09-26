create or replace trigger DontDecrementSal
before
update
on emp
for each row

BEGIN
  IF :new.esal < :old.esal THEN
    raise_application_error(-20001, 'Cannot decrement the salray');
  END IF;
END;
/