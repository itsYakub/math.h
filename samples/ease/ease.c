#include <raylib.h>

#include "./../../ease.h"

int main() {
    InitWindow(800, 600, "math.h - raylib - easing sample");
    
    float t = 0.0;
    float t_scale = 2.0;
    Rectangle rects[32] = {
        { 0.0, 0.0, 16.0, 16.0 }
    };
    
    for (size_t i = 1; i < sizeof(rects) / sizeof(Rectangle); i++) {
        rects[i].x = 0.0;
        rects[i].y = rects[i - 1].y + rects[i - 1].height;
        rects[i].width = rects[i].height = rects[i - 1].width;
    }

    float (*f[])(const float) = {
        easeIn_sine, easeOut_sine,
        easeIn_quad, easeOut_quad,
        easeIn_cubic, easeOut_cubic,
        easeIn_back, easeOut_back,

        /* FIXME: broken formulas
         * */
        easeIn_elastic, easeOut_elastic,

        easeIn_bounce, easeOut_bounce,
    };

    while (!WindowShouldClose()) {
        ClearBackground(BLACK);

        if (IsKeyReleased(KEY_R)) { t = 0.0; }
        if (IsKeyReleased(KEY_UP)) { t_scale += 0.5; }
        if (IsKeyReleased(KEY_DOWN)) { t_scale -= 0.5; }
        t_scale = clamp(t_scale, 0.5, 10.0);

        t += GetFrameTime() / t_scale;
        for (size_t i = 0; i < sizeof(f) / sizeof(float *); i++) {
            rects[i].x = f[i](t) * GetScreenWidth() - rects[i].width;
        }

        BeginDrawing();
        
        for (size_t i = 0; i < sizeof(f) / sizeof(float *); i++) {
            DrawRectangleRec(rects[i], RED);
        }

        DrawText(TextFormat("Time: %.2f | Time Scale: %.02f", t, t_scale), 0, GetScreenHeight() - 32, 32, GREEN);
        EndDrawing();
    }

    CloseWindow();
}
