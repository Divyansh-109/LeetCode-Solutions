import pandas as pd

def getDataframeSize(players: pd.DataFrame) -> List[int]:
    [row, column] = players.shape
    return [row, column]
