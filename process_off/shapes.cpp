#include "shapes.hpp"
#include "utility_funcs.hpp"
#include <vector>
#include <memory>
#include <cmath>

Model cube() {
    std::vector<std::shared_ptr<Point>> points;
    for (int i = 0 ; i < 2 ; i++) for (int k = 0 ; k < 2 ; k++) for (int m = 0 ; m < 2 ; m++)
                points.push_back(std::make_shared<Point>(i, k, m));

    std::shared_ptr<Point> barycenter = calculateBarycenter(points);

    std::vector<std::shared_ptr<Plane>> faces = {
            std::make_shared<Plane>(points[0], points[4], points[1], barycenter),
            std::make_shared<Plane>(points[2], points[0], points[3], barycenter),
            std::make_shared<Plane>(points[2], points[3], points[6], barycenter),
            std::make_shared<Plane>(points[4], points[6], points[5], barycenter),
            std::make_shared<Plane>(points[0], points[2], points[4], barycenter),
            std::make_shared<Plane>(points[1], points[5], points[3], barycenter)
    };

    Model shape = {points, faces, "cube", barycenter};
    return shape;
}


Model tetrahedron() {
    std::vector<std::shared_ptr<Point>> points = {
            std::make_shared<Point>(0, 0, 0),
            std::make_shared<Point>(1, 0, 0),
            std::make_shared<Point>(0.5, std::sqrt(3)/2, 0),
            std::make_shared<Point>(0.5, std::sqrt(3)/4, std::sqrt(3)/2)
    };

    std::shared_ptr<Point> barycenter = calculateBarycenter(points);

    std::vector<std::shared_ptr<Plane>> faces = {
            std::make_shared<Plane>(points[0], points[1], points[3], barycenter),
            std::make_shared<Plane>(points[2], points[0], points[3], barycenter),
            std::make_shared<Plane>(points[2], points[3], points[1], barycenter),
            std::make_shared<Plane>(points[0], points[2], points[1], barycenter)
    };

    Model shape = {points, faces, "tetrahedron", barycenter};
    return shape;
}

Model octahedron() {
    std::vector<std::shared_ptr<Point>> points = {
            std::make_shared<Point>(0, 0, 0),
            std::make_shared<Point>(1, 0, 0),
            std::make_shared<Point>(1, 1, 0),
            std::make_shared<Point>(0, 1, 0),
            std::make_shared<Point>(0.5, 0.5, 1/std::sqrt(2)),
            std::make_shared<Point>(0.5, 0.5, - 1/std::sqrt(2))
    };

    std::shared_ptr<Point> barycenter = calculateBarycenter(points);

    std::vector<std::shared_ptr<Plane>> faces = {
            std::make_shared<Plane>(points[0], points[1], points[4], barycenter),
            std::make_shared<Plane>(points[1], points[2], points[4], barycenter),
            std::make_shared<Plane>(points[2], points[3], points[4], barycenter),
            std::make_shared<Plane>(points[3], points[0], points[4], barycenter),
            std::make_shared<Plane>(points[0], points[1], points[5], barycenter),
            std::make_shared<Plane>(points[1], points[2], points[5], barycenter),
            std::make_shared<Plane>(points[2], points[3], points[5], barycenter),
            std::make_shared<Plane>(points[3], points[0], points[5], barycenter)
    };

    Model shape = {points, faces, "octahedron", barycenter};
    return shape;
}

Model dodecahedron() {
    float goldenRatio = (float) (1 + std::sqrt(5))/2;
    std::vector<std::shared_ptr<Point>> points;
    for (int i = 0 ; i < 2 ; i++)
        for (int k = 0 ; k < 2 ; k++) {
            float cfI = i == 1 ? -1 : 1;
            float cfK = k == 1 ? -1 : 1;
            points.push_back(std::make_shared<Point>(0, cfI * (1 / goldenRatio), cfK * goldenRatio));
        }
    for (int i = 0 ; i < 2 ; i++)
        for (int k = 0 ; k < 2 ; k++) {
            float cfI = i == 1 ? -1 : 1;
            float cfK = k == 1 ? -1 : 1;
            points.push_back(std::make_shared<Point>(cfI * (1 / goldenRatio), cfK * goldenRatio, 0));
        }
    for (int i = 0 ; i < 2 ; i++)
        for (int k = 0 ; k < 2 ; k++)
            for (int m = 0 ; m < 2 ; m++){
                float cfI = i == 1 ? -1 : 1;
                float cfK = k == 1 ? -1 : 1;
                float cfM = m == 1 ? -1 : 1;
                points.push_back(std::make_shared<Point>(cfI, cfK, cfM));
            }
    for (int i = 0 ; i < 2 ; i++)
        for (int k = 0 ; k < 2 ; k++) {
            float cfI = i == 1 ? -1 : 1;
            float cfK = k == 1 ? -1 : 1;
            points.push_back(std::make_shared<Point>(cfI * goldenRatio, 0, cfK * (1 / goldenRatio)));
        }

    std::shared_ptr<Point> barycenter = calculateBarycenter(points);

    std::vector<std::shared_ptr<Plane>> faces = {
            std::make_shared<Plane>(points[5], points[7], points[14], barycenter),
            std::make_shared<Plane>(points[0], points[8], points[4], barycenter),
            std::make_shared<Plane>(points[4], points[9], points[1], barycenter),
            std::make_shared<Plane>(points[11], points[3], points[15], barycenter),
            std::make_shared<Plane>(points[0], points[12], points[18], barycenter),
            std::make_shared<Plane>(points[16], points[10], points[2], barycenter),
            std::make_shared<Plane>(points[18], points[12], points[6], barycenter),
            std::make_shared<Plane>(points[19], points[15], points[7], barycenter),
            std::make_shared<Plane>(points[19], points[13], points[1], barycenter),
            std::make_shared<Plane>(points[5], points[10], points[16], barycenter),
            std::make_shared<Plane>(points[16], points[8], points[4], barycenter),
            std::make_shared<Plane>(points[11], points[17], points[9], barycenter)
    };

    Model shape = {points, faces, "dodecahedron", barycenter};
    return shape;
}

Model icosahedron() {
    float goldenRatio = (float) (1 + std::sqrt(5))/2;
    std::vector<std::shared_ptr<Point>> points;
    for (int i = 0 ; i < 2 ; i++)
        for (int k = 0 ; k < 2 ; k++) {
            float cfI = i == 1 ? -1 : 1;
            float cfK = k == 1 ? -1 : 1;
            points.push_back(std::make_shared<Point>(cfI * goldenRatio, cfK, 0));
        }
    for (int i = 0 ; i < 2 ; i++)
        for (int k = 0 ; k < 2 ; k++) {
            float cfI = i == 1 ? -1 : 1;
            float cfK = k == 1 ? -1 : 1;
            points.push_back(std::make_shared<Point>(cfI, 0, cfK * goldenRatio));
        }
    for (int i = 0 ; i < 2 ; i++)
        for (int k = 0 ; k < 2 ; k++) {
            float cfI = i == 1 ? -1 : 1;
            float cfK = k == 1 ? -1 : 1;
            points.push_back(std::make_shared<Point>(0, cfI * goldenRatio, cfK));
        }

    std::shared_ptr<Point> barycenter = calculateBarycenter(points);

    std::vector<std::shared_ptr<Plane>> faces = {
            std::make_shared<Plane>(points[4], points[6], points[8], barycenter),
            std::make_shared<Plane>(points[6], points[10], points[4], barycenter),
            std::make_shared<Plane>(points[4], points[1], points[0], barycenter),
            std::make_shared<Plane>(points[1], points[10], points[4], barycenter),
            std::make_shared<Plane>(points[0], points[4], points[8], barycenter),
            std::make_shared<Plane>(points[2], points[6], points[8], barycenter),
            std::make_shared<Plane>(points[2], points[3], points[6], barycenter),
            std::make_shared<Plane>(points[3], points[6], points[10], barycenter),
            std::make_shared<Plane>(points[3], points[10], points[11], barycenter),
            std::make_shared<Plane>(points[11], points[1], points[10], barycenter),
            std::make_shared<Plane>(points[1], points[5], points[0], barycenter),
            std::make_shared<Plane>(points[11], points[1], points[5], barycenter),
            std::make_shared<Plane>(points[0], points[9], points[5], barycenter),
            std::make_shared<Plane>(points[9], points[8], points[0], barycenter),
            std::make_shared<Plane>(points[9], points[8], points[2], barycenter),
            std::make_shared<Plane>(points[9], points[7], points[2], barycenter),
            std::make_shared<Plane>(points[7], points[2], points[3], barycenter),
            std::make_shared<Plane>(points[7], points[11], points[3], barycenter),
            std::make_shared<Plane>(points[7], points[5], points[11], barycenter),
            std::make_shared<Plane>(points[9], points[7], points[5], barycenter)
    };

    Model shape = {points, faces, "icosahedron", barycenter};
    return shape;
}
