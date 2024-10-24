import pandas as pd

def selectFirstRows(employees: pd.DataFrame) -> pd.DataFrame:
    selected_rows = employees.head(3)
    return selected_rows
