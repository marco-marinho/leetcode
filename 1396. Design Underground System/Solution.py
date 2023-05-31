class UndergroundSystem:

    def __init__(self):
        self.averages: dict[(str, str), (int, int)] = {}
        self.travelling: dict[int, (str, int)] = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.travelling[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        start, start_t = self.travelling.pop(id)
        key = (start, stationName)
        cur_total, cur_num = self.averages.get(key, (0, 0))
        self.averages[key] = (cur_total + (t - start_t), cur_num + 1)

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        total, n = self.averages.get((startStation, endStation), (0, 0))
        return total / n