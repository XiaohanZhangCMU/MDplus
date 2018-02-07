data109b = [ %relax surrounding atoms (initial path from cstmin)
0.000000e+00      0.000000000000000e+00
5.000000e-02      9.727186996315140e-03
1.000000e-01      3.493165247346042e-02
1.500000e-01      7.998359402699862e-02
2.000000e-01      1.446412584809877e-01
2.500000e-01      2.215906388155418e-01
3.000000e-01      3.012396742888086e-01
3.500000e-01      3.765480404181289e-01
4.000000e-01      4.415366035354964e-01
4.500000e-01      4.824009854783071e-01
5.000000e-01      4.801522166344512e-01
5.500000e-01      4.302681686531287e-01
6.000000e-01      3.404768051550491e-01
6.500000e-01      2.262615328945685e-01
7.000000e-01      1.033019740025338e-01
7.500000e-01     -2.775706381362397e-02
8.000000e-01     -1.511673645945848e-01
8.500000e-01     -2.713131954806158e-01
9.000000e-01     -3.618479612705414e-01
9.500000e-01     -4.136677988572046e-01
1.000000e+00     -4.297535125588183e-01];   

data109a = [ %relax surrounding atoms
0.000000e+00      0.000000000000000e+00
5.000000e-02      5.907673152250936e-03
1.000000e-01      2.186912598335766e-02
1.500000e-01      5.081512379547348e-02
2.000000e-01      9.637571226267028e-02
2.500000e-01      1.625082041646237e-01
3.000000e-01      2.472431829228299e-01
3.500000e-01      3.406483541366470e-01
4.000000e-01      4.275431890018808e-01
4.500000e-01      4.819244631835318e-01
5.000000e-01      4.770170363844954e-01
5.500000e-01      4.096597398274753e-01
6.000000e-01      2.925254638212209e-01
6.500000e-01      1.480109579606506e-01
7.000000e-01      2.158674447855446e-03
7.500000e-01     -1.305619979066250e-01
8.000000e-01     -2.443557587903342e-01
8.500000e-01     -3.329066807200434e-01
9.000000e-01     -3.911293514684075e-01
9.500000e-01     -4.208871897099016e-01
1.000000e+00     -4.297584939049557e-01];   

data109 = [ %interpolate surrounding atoms
0.000000e+00      0.000000000000000e+00
5.000000e-02      6.923174085386563e-03
1.000000e-01      2.475786251306999e-02
1.500000e-01      5.632905881066108e-02
2.000000e-01      1.046520937306923e-01
2.500000e-01      1.735491008439567e-01
3.000000e-01      2.614389909904276e-01
3.500000e-01      3.581362348450057e-01
4.000000e-01      4.473260697814112e-01
4.500000e-01      5.015506217860093e-01
5.000000e-01      4.957586668897420e-01
5.500000e-01      4.273356284102192e-01
6.000000e-01      3.087187924575119e-01
6.500000e-01      1.622304737538798e-01
7.000000e-01      1.404626750081661e-02
7.500000e-01     -1.204918142502720e-01
8.000000e-01     -2.360125864615839e-01
8.500000e-01     -3.265168755970080e-01
9.000000e-01     -3.862265581119573e-01
9.500000e-01     -4.190963863547950e-01
1.000000e+00     -4.297569588525221e-01
];

data39 = [
0.000000e+00      0.000000000000000e+00
5.000000e-02      8.669675818964606e-03
1.000000e-01      3.144422608602326e-02
1.500000e-01      7.064398158036056e-02
2.000000e-01      1.291622427706898e-01
2.500000e-01      2.101077131555940e-01
3.000000e-01      3.091342466977949e-01
3.500000e-01      4.145485587396252e-01
4.000000e-01      5.079437726708420e-01
4.500000e-01      5.637489584260038e-01
5.000000e-01      5.600746157579124e-01
5.500000e-01      4.923064824870380e-01
6.000000e-01      3.722931756856269e-01
6.500000e-01      2.211046660340799e-01
7.000000e-01      6.445163261014386e-02
7.500000e-01     -7.889863098171190e-02
8.000000e-01     -2.034917487690109e-01
8.500000e-01     -3.055024782443070e-01
9.000000e-01     -3.772818216093583e-01
9.500000e-01     -4.169558788489667e-01
1.000000e+00     -4.297569588525221e-01];

data=data109b;
%data=data109a;
%data=data109;
%data=data39;
s=data(:,1);
E=data(:,2);
figure(1);
plot(s,E,'ro-');

max(E)