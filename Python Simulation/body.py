

class Body:
    def __init__(self, mass, friction=1.0, destination=70, start = 0):
        self._mass = mass
        self._friction = friction
        self._destination = destination
        self._position = 0.0
        self._velocity = 0.0
        self._acceleration = 0.0
        self._cumulative_error = 0.0
        self._last_error = 0.0

        self.previous_position = []
        self.previous_velocity = []
        self.previous_acceleration = []

    def update(self, kp, ki, kd, dt):
        error = self._destination - self._position

        # PID terms
        proportional = kp * error
        self._cumulative_error += error * dt
        integral = ki * self._cumulative_error

        d_error = (error - self._last_error) / dt
        derivative = kd * d_error

        # PID force and friction
        force = proportional + integral + derivative - self._friction * self._velocity
        self._acceleration = force / self._mass

        # Integrate motion
        self._velocity += self._acceleration * dt
        self._position += self._velocity * dt

        # Save states
        self.previous_position.append(self._position)
        self.previous_velocity.append(self._velocity)
        self.previous_acceleration.append(self._acceleration)

        self._last_error = error

        @property
        def position(self):
            return self._position

        @position.getter
        def position(self):
            return self._position