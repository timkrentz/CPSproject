rw.x = 0;
rw.y = 0;
fw.x = 0;
fw.y = 16;
heading = 90;

wheelBase = 16;

velocity = 50; %cm/s
timestep = 0.05; %seconds
wheelAngle = 60; %/degrees
figure(1)
clf(1)
axis([-100,100,-100,100])
hold on

for t = 1:100
    
    scatter(rw.x,rw.y,'ro')
    scatter(fw.x,fw.y,'bo')
    if(wheelAngle == 90)
        wheelAngle = wheelAngle + 0.0001;
    end
    alpha = wheelAngle;
    turningRadius = tand(alpha)*wheelBase;
    arcLength = velocity * timestep;
    theta = arcLength / turningRadius;
    theta = theta * (180/pi);
    
    dx = turningRadius - (cosd(theta)*turningRadius);
    dy = sind(theta)*turningRadius;
    
    rw.x = rw.x + cosd(heading)*dx + cosd(heading)*dy;
    rw.y = rw.y + sind(heading)*dx + sind(heading)*dy;
    heading = heading - theta;
    fw.x = rw.x + cosd(heading)*wheelBase;
    fw.y = rw.y + sind(heading)*wheelBase;
%     pause(0.001)
    
end
% 
% wheelAngle = 120;
% 
% for t = 1:100
%     
%     scatter(rw.x,rw.y,'ro')
%     scatter(fw.x,fw.y,'bo')
%     alpha = 90-wheelAngle;
%     turningRadius = tand(alpha)*wheelBase;
%     arcLength = velocity * timestep;
%     theta = arcLength / turningRadius;
%     theta = theta * (180/pi);
%     
%     dx = turningRadius - (cosd(theta)*turningRadius);
%     dy = sind(theta)*turningRadius;
%     
%     rw.x = rw.x + cosd(heading)*dx + cosd(heading)*dy;
%     rw.y = rw.y + sind(heading)*dx + sind(heading)*dy;
%     heading = heading - theta;
%     fw.x = rw.x + cosd(heading)*wheelBase;
%     fw.y = rw.y + sind(heading)*wheelBase;
%     pause(0.001)
%     
% end