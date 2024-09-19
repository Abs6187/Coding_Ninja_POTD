/*
    Time Complexity: O(N*log(N))
    Space Complexity: O(N)

	where 'N' is the given number of rectangles.
*/

int perfectRectangle(vector<vector<int>> &rectangles)
{

    // Variable to store the sum of areas of all small rectangles
    int totalArea = 0;

    // Set to store the corners of all small rectangles
    set<pair<int, int>> corners;

    for (vector<int> &rect : rectangles)
    {
        pair<int, int> currentCorners[4] = {{rect[0], rect[1]}, {rect[2], rect[3]}, {rect[0], rect[3]}, {rect[2], rect[1]}};

        totalArea += (rect[2] - rect[0]) * (rect[3] - rect[1]);

        // Check if any of the corners exist in the set 'corner'
        for (int i = 0; i < 4; i++)
        {
            if (corners.count(currentCorners[i]) > 0)
            {
                corners.erase(currentCorners[i]);
            }
            else
            {
                corners.insert(currentCorners[i]);
            }
        }
    }

    // If set 'corners' doesn't contains exactly 4 corners
    if (corners.size() != 4)
    {
        return 0;
    }

    // Calculating the area of bigger rectangle using 4 corners
    pair<int, int> firstCorner = *corners.begin(), lastCorner = *corners.rbegin();

    int desiredArea = (lastCorner.second - firstCorner.second) * (lastCorner.first - firstCorner.first);

    // If both the areas are not equal
    if (totalArea != desiredArea)
    {
        return 0;
    }

    return 1;
}
