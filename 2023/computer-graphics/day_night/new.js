// import * as THREE from 'three';
import * as THREE from 'https://cdn.jsdelivr.net/npm/three@0.117.1/build/three.module.js';
import { OrbitControls } from 'https://cdn.jsdelivr.net/npm/three@0.117.1/examples/jsm/controls/OrbitControls.js';

// Set up scene
const scene = new THREE.Scene();

// Set up camera
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
camera.position.z = 5;

// Set up renderer
const renderer = new THREE.WebGLRenderer();
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

// Load starfield texture
const starfieldTexture = new THREE.TextureLoader().load('textures/starfield.jpg');

// Create cube with starfield texture for the background
const cubeGeometry = new THREE.BoxGeometry(100, 100, 100);
const cubeMaterial = new THREE.MeshBasicMaterial({ map: starfieldTexture, side: THREE.BackSide });
const starfieldCube = new THREE.Mesh(cubeGeometry, cubeMaterial);
scene.add(starfieldCube);

// Load texture for Earth
const earthTexture = new THREE.TextureLoader().load('textures/earth.jpg');

// Create Earth-like object with texture
const earthGeometry = new THREE.SphereGeometry(1, 32, 32);
const earthMaterial = new THREE.MeshPhongMaterial({ map: earthTexture });
const earth = new THREE.Mesh(earthGeometry, earthMaterial);
scene.add(earth);

// Create mesh to represent the sun
const sunGeometry = new THREE.SphereGeometry(1, 32, 32);
const sunMaterial = new THREE.MeshBasicMaterial({ color: 0xffffff });
const sun = new THREE.Mesh(sunGeometry, sunMaterial);
scene.add(sun);

// Create directional light representing the sun
const sunLight = new THREE.DirectionalLight(0xffffff, 1);
scene.add(sunLight);

// Set up clock for animation
const clock = new THREE.Clock();

const controls = new OrbitControls(camera, renderer.domElement);
controls.enableDamping = true; // an animation loop is required when either damping or auto-rotation are enabled
controls.dampingFactor = 0.25;
controls.screenSpacePanning = false;

const flipCameraButton = document.createElement('button');
flipCameraButton.textContent = 'Flip Camera X View';
document.body.appendChild(flipCameraButton);

flipCameraButton.addEventListener('click', () => {
  // Change the camera's x view by 180 degrees
  //camera.rotation.y += Math.PI;
  camera.position.z *= -1;
  // Update controls to apply changes
  controls.update();
});

// Update function
const update = () => {
  const delta = clock.getDelta();

  // Rotate the Earth
  earth.rotation.y += 0.1 * delta;

  // Rotate the sun around the Earth
  const sunSpeed = 0.5;
  const angle = clock.elapsedTime * sunSpeed;
  const distance = 10;
  sunLight.position.set(Math.cos(angle) * distance, 0, Math.sin(angle) * distance);

  // Rotate the sun mesh to follow the light source
  sun.rotation.y += 0.1 * delta;
  sun.position.set(Math.cos(angle) * distance, 0, Math.sin(angle) * distance);

  // Render the scene
  renderer.render(scene, camera);

  // Call update again on the next frame
  requestAnimationFrame(update);
  controls.update();
};

// Start the animation loop
update();

// Handle window resize
window.addEventListener("resize", () => {
  camera.aspect = window.innerWidth / window.innerHeight;
  camera.updateProjectionMatrix();
  renderer.setSize(window.innerWidth, window.innerHeight);
});
