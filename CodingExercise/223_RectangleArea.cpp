class Solution {
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int area_intersect = 0;
    int area_all = (C-A) * (D-B) + (G-E) * (H-F);
    if (!(A >= G || C <= E || B >= H || D <= F)) {
      area_intersect = (min(D,H) - max(B,F)) * (min(C,G) - max(A,E));
    }
    return area_all - area_intersect;
  }
};
