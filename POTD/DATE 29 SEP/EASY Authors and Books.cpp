#include <vector>
#include <string>

std::vector<std::string> arrangeAuthors(const std::vector<std::vector<std::string>>& authors) {
    std::vector<std::string> result;
    result.reserve(authors.size() * 2);  // Estimate capacity to reduce reallocations

    for (size_t i = 0; i < authors.size(); ++i) {
        result.push_back(std::to_string(i + 1) + ". " + authors[i][0]);

        for (size_t j = 1; j < authors[i].size(); ++j) {
            result.push_back(std::string(1, 'A' + j - 1) + ". " + authors[i][j]);
        }
    }

    return result;
}
