class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key=lambda x: x[1], reverse=True)
        total_units = 0
        for boxes, units in boxTypes:
            if truckSize == 0:
                break
            box_to_take = min(boxes, truckSize)
            total_units += box_to_take * units
            truckSize -= box_to_take
        return total_units
        