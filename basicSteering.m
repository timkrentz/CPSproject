rw.x = 0;
rw.y = 0;
fw.x = 0;
fw.y = 16;
heading = 90;

wheelBase = 16;

velocity = 5; %cm/s
timestep = 0.05; %seconds
wheelAngle = 50; %/degrees

for t = 1:100
    alpha = 90-wheelAngle;
    turningRadius = tand(alpha)*wheelBase;
    arcLength = velocity / timestep;
    theta = arcLength / (2*pi*turningRadius);
    
    dx = turningRadius - (cosd(theta)/turningRadius);
    dy = sind(theta)/turningRadius;
    
    rw.x = rw.x + dx;
    rw.y = rw.y + dy;
    
    