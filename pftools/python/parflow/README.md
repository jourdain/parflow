To run tests on the inconsistencies and the pf-key modifications that fix them:
1) Make a virtual env with the requirements.txt
2) Run inconsistency_failures.py to see failures with imported pf-key definitions
3) Generate a module from the fixed keys with `python ../../../pf-keys/generators/pf-python.py tools/database/generated.py`
4) Run succeeding tests with `python inconsistency_success_after_changes.py`
