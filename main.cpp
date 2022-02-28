#include <Magick++.h>
#include <filesystem>
#include <fstream>

using namespace std;
using namespace Magick;
namespace fs = std::filesystem;

/**
 * 使用 Magick++ 对gif图片进行批量抽帧处理
 */
int main() {
    string baseSavePath = R"(D:\Telegram\AnimatedEmojies\)";
    for (const auto &entry: fs::directory_iterator(R"(D:\Telegram\AnimatedEmojies-256px)")) {
        if (entry.path().extension() == ".gif") {
            printf("FilePath -> %ls\n", entry.path().c_str());
            list<Image> imageList;
            readImages(&imageList, entry.path().string());
            printf("Frame -> %llu\n", imageList.size());

            int skip = 0;
            list<Image> saveList;
            for (const auto &item: imageList) {
                if (!(skip++ % 2)) {
                    continue;
                }
                saveList.push_back(item);
            }

            auto *newPath = new string(baseSavePath);
            newPath->append(entry.path().filename().string());
            printf("SavePath -> %s\n", newPath->c_str());
            writeImages(saveList.begin(), saveList.end(), *newPath);
            delete newPath;
        }
    }
    return 0;
}